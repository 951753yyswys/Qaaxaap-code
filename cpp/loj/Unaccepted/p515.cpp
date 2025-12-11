#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    void work()
    {
        int n;
        cin>>n;
        vector<int> a(n+1),b(n+1);
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
        bitset<1000010> dp[2];
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            int nc=i%2;
            int yc=nc^1;
            dp[nc].reset();
            for(int j=a[i];j<=b[i];j++)
            {
                dp[nc]|=dp[yc]<<j*j;
            }
        }
        cout<<dp[n%2].count();
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}