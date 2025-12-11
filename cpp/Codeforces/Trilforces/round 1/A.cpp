#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    int ans=0;
    pair<int,int> dfs(int ro,vector<vector<int>> &g,string &co)
    {
        int b=0,w=0;
        for(auto tmp:g[ro]) 
        {
            pair<int,int> dw=dfs(tmp,g,co);
            b+=dw.first;
            w+=dw.second;
        }
        if(co[ro]=='B') b++;
        else w++;
        if(b==w) ans++;
        return {b,w};
    }
    void work()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int n;
            ans=0;
            cin>>n;
            vector<vector<int>> g(n+1);
            for(int i=2;i<=n;i++)
            {
                int tmp;
                cin>>tmp;
                g[tmp].push_back(i);
            }
            string co;
            cin>>co;
            co='#'+co;
            dfs(1,g,co);
            cout<<ans<<endl;    
        }
        
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}