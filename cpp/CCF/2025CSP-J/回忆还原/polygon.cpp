#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int a[101010],dp[5050],ldp[5050];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,mx=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
    sort(a+1,a+n+1);
    int ans=0;
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=mx+1;j++) ldp[j]=dp[j];
        for(int j=a[i]+1;j<=mx+1;j++) ans=(ans+dp[j])%mod;
        for(int j=0;j<=mx+1;j++) dp[min(j+a[i],mx+1)]=(dp[min(j+a[i],mx+1)]+ldp[j])%mod;
    }
    cout<<ans;
    return 0;
} 