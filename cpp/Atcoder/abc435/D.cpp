#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    void work()
    {
        int n,m,q;
        cin>>n>>m;
        vector<vector<int>> g(n+1);
        vector<int> col(n+1);
        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            g[v].push_back(u);
        }
        cin>>q;
        while(q--)
        {
            int opt,ro;
            cin>>opt>>ro;
            if(opt==1)
            {
                queue<int> qu;
                if(col[ro]) continue;
                col[ro]=1;
                qu.push(ro);
                while(!qu.empty())
                {
                    int u;
                    u=qu.front();
                    qu.pop();
                    for(auto v:g[u])
                    {
                        if(col[v]) continue;
                        col[v]=1;
                        qu.push(v);
                    }
                }
            }
            else 
            {
                if(col[ro]) cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return Qaaxaap::work(),0;
}