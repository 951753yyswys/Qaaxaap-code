#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    int g[1010][1010];
    void work()
    {
        int T;
        cin>>T;
        while(T--)
        {
            int n;
            cin>>n;
            for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) g[i][j]=(i-1)*n+j;
            for(int i=1;i<=n+1;i++) g[i][n+1]=g[n+1][i]=0;
            int ans=0;
            for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ans=max(ans,g[i-1][j]+g[i][j]+g[i+1][j]+g[i][j-1]+g[i][j+1]);
            // for(int i=1;i<=n+1;i++)
            // {
            //     for(int j=1;j<=n+1;j++) cout<<g[i][j]<<' ';
            //     cout<<endl;
            // }
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