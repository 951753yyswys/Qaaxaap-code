#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    char dtc(int d) 
    {
        if(d%3==0) return 'r';
        if(d%3==1) return 'g';
        return 'b';
    }
    char gcy(char c) 
    {
        if(c=='r') return 'g';
        if(c=='g') return 'b';
        return 'r'; 
    }
	void work()
	{
        string opt;
        cin>>opt;
        int t;
        cin>>t;
        if(opt=="first") 
        {
            while(t--) 
            {
                int n,m;
                cin>>n>>m;
                vector<vector<int>> g(n+1);
                for(int i=1;i<=m;i++) 
                {
                    int a,b;
                    cin>>a>>b;
                    g[a].push_back(b);
                    g[b].push_back(a);
                }
                vector<int> dis(n+1,-1);
                queue<int> q;
                dis[1]=0;
                q.push(1);
                while(!q.empty()) 
                {
                    int v=q.front(); 
                    q.pop();
                    for(auto u:g[v]) if(dis[u]==-1) dis[u]=dis[v]+1,q.push(u);
                }
                string ans;
                ans.resize(n);
                for(int i=0;i<n;i++) ans[i]=dtc(dis[i+1]);
                cout<<ans<<endl;
            }
        } 
        else 
        {
            while(t--) 
            {
                int q;
                cin>>q;
                while(q--) 
                {
                    int d;
                    cin>>d;
                    string c;
                    cin>>c;
                    int hr=0,hg=0,hb=0;
                    for(auto tmp:c) 
                    {
                        if(tmp=='r') hr=1;
                        else if(tmp=='g') hg=1;
                        else hb=1; 
                    }
                    int dis=hr+hg+hb;
                    char cs;
                    if(dis==1) cs=c[0]; 
                    else 
                    {
                        char a=c[0],b=0;
                        for(auto tmp:c) if(tmp!=a) 
                        { 
                            b=tmp; 
                            break; 
                        }
                        if(gcy(a)==b)cs=b;
                        else cs=a;
                    }
                    int ans=1;
                    for(int i=0;i<d;i++) if(c[i]==cs) 
                    {
                        ans=i+1; 
                        break;
                    }
                    cout<<ans<<endl;
                }
            }
        }
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}