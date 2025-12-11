#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 19650827
int a[10101],dp[1010][1010][2];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) 
        cin>>a[i],dp[i][i][1]=dp[i][i][0]=1;
    for(int len=2;len<=n;len++) 
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            if(a[i]<a[i+1]) 
                dp[i][j][1]=(dp[i][j][1]+dp[i+1][j][1])%mod;
            if(a[i]<a[j]) 
                dp[i][j][1]=(dp[i][j][1]+dp[i+1][j][0])%mod;
            if(a[j]>a[j-1]) 
                dp[i][j][0]=(dp[i][j][0]+dp[i][j-1][0])%mod;
            if(a[j]>a[i]) 
                dp[i][j][0]=(dp[i][j][0]+dp[i][j-1][1])%mod;
            if(len==2) dp[i][j][0]/=2,dp[i][j][1]/=2;
        }
    }
    cout<<(dp[1][n][0]+dp[1][n][1])%mod;
    return 0;
} 