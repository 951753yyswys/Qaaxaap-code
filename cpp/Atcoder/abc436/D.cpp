#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    char mp[1010][1010];
    void work()
    {
        int h,w;
        cin>>h>>w;
        vector<vector<pair<int,int>>> buc(128);
        for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) 
        {
            cin>>mp[i][j];
            char c=mp[i][j];
            if(c<='z'&&c>='a') buc[c].push_back({i,j});
        }
        queue<pair<int,int>> q;
        map<pair<int,int>,int> dis;
        dis[{1,1}]=1;
        q.push({1,1});
        vector<int> vis(128);
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            char c=mp[x][y];
            if(mp[x][y]<='z'&&mp[x][y]>='a') 
            {
                if(!vis[c]) 
                {
                    vis[c]=1;
                    int di=dis[{x,y}];
                    for(auto tmp:buc[c]) if(dis[tmp]==0) dis[tmp]=di+1,q.push(tmp);
                }
            }
            for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++)
            {
                if(i!=0&&j!=0) continue;
                int dx=x+i;
                int dy=y+j;
                if(dx<1) continue;
                if(dy<1) continue;
                if(dx>h) continue;
                if(dy>w) continue;  
                if(mp[dx][dy]=='#') continue;
                if(dis[{dx,dy}]==0) q.push({dx,dy}),dis[{dx,dy}]=dis[{x,y}]+1;
            }
        }
        cout<<dis[{h,w}]-1;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return Qaaxaap::work(),0;
} 