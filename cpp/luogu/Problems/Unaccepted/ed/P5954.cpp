
#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    void work()
    {
        int n,m,D;
        cin>>n>>m>>D;
        vector<vector<int>> g(n+1),fg(n+1);
        vector<int> d(n+1);
        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            fg[v].push_back(u);
            d[u]++;
        }
        queue<int> q;
        for(int i=1;i<=n;i++) if(d[i]==0) q.push(i);
        vector<int> s;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            s.push_back(u);
            for(auto tmp:fg[u]) 
            {
                d[tmp]--;
                if(d[tmp]<=0) q.push(tmp);
            }
        }
        
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}