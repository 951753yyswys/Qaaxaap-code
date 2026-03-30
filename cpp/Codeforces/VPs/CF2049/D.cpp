#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[202][202][202],f[202][202],a[202][202];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,yk;
        cin>>n>>m>>yk;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
            {
                f[i][j]=1e15;
                for(int k=0;k<=m;k++) 
                    dp[i][j][k]=1e15;
            }
        f[0][1]=0;
        for(int i=1;i<=n;i++) 
            for(int j=1;j<=m;j++) 
                cin>>a[i][j];
        for(int i=1;i<=n;i++)
        {
            for(int k=0;k<m;k++)
                for(int j=1;j<=m;j++) 
                {
                    dp[i][j][k]=min(f[i-1][j]+k*yk,dp[i][(j-2+m)%m+1][k])+a[i][(j+k-1)%m+1];
                    f[i][j]=min(f[i][j],dp[i][j][k]);
                }
        }
        cout<<f[n][m]<<endl;
    }
    return 0;
} 