#include<bits/stdc++.h>
using namespace std;
#define double long double 
#define int long long
double x[101010],y[101010];
int dp[1010][1010][2],hd[1010];
double len3(int a,int b)
{
    return sqrtl((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            if(dp[i][j][1]>dp[i][j-1][1]+len3(j-1,j)) hd[j]=j-1;
            if(dp[i][j][0]>dp[i+1][j-1][])
        }
    }
    return 0;
} 