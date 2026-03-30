#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
#define int long long
int dp[1010101],a[1010101],t[1010101],p[202],s[1010101];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,n,T;
    cin>>c>>n>>T;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>t[i];
    p[0]=1;
    for(int i=1;i<=200;i++) p[i]=p[i-1]*2%mod;
    for(int i=1;i<=n;i++) s[i]=(s[i-1]+t[i])%mod;
    dp[0]=1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=0;j+t[i]<=T;j++)
            sum=(sum+dp[j])%mod;
        ans=(ans+a[i]*sum%mod*p[n-i]%mod)%mod;
        for(int j=T;j>=t[i];j--) 
            dp[j]=(dp[j]+dp[j-t[i]])%mod;
    }
    for(int i=1;i<=T;i++) dp[i]=0;
    dp[0]=1;
    for(int i=n;i>=1;i--)
    {
        int sum=0;
        for(int j=0;j+s[i]<=T;j++)
            sum=(sum+dp[j])%mod;
        ans=(ans+a[i]*sum%mod*p[i-1]%mod)%mod;
        for(int j=T;j>=t[i];j--) 
            dp[j]=(dp[j]+dp[j-t[i]])%mod;
    }
    cout<<ans;
    return 0;
} 