#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    vector<int> dij(int s,int n,vector<vector<pair<int,int>>>& g)
    {
        vector<int> dis(n+1,0x7fffffffffffffff),vis(n+1);
        dis[s]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,s});
        while(!q.empty())
        {
            int u=q.top().second;
            q.pop();
            if(vis[u]) continue;
            vis[u]=1;
            for(auto tmp:g[u])
            {
                int v=tmp.first;
                int w=tmp.second;
                if(dis[v]>dis[u]+w) 
                {
                    dis[v]=dis[u]+w;
                    q.push({dis[v],v});
                }
            }
        }
        return dis;
    }
    void work()
    {
        int n,m,s;
        cin>>n>>m>>s;
        vector<vector<pair<int,int>>> g(n+1);
        for(int i=1;i<=m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            g[u].push_back({v,w});
        }
        vector<int> dis;
        dis=move(dij(s,n,g));
        for(int i=1;i<=n;i++) cout<<dis[i]<<' ';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}