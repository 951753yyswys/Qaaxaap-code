#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int dp[505][505][7];
/*
0 *..........*
1 (....)*....*
2 *....*(....)
3 *..*(..)*..*
4 (..)*..*(..)
5 (..........)
*/
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    s='#'+s;
    for(int i=1;i<=n;i++) 
    {
        for(int b=0;b<=5;b++) dp[i][i][b]=0;
        if(s[i]=='*'||s[i]=='?') dp[i][i][0]=1;
    }
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            if(s[j]=='*'||s[j]=='?') 
            {
                dp[i][j][0]+=dp[i][j-1][0];

            }
            if(s[i]=='*'||s[j]=='?') dp[i][j][0]+=dp[i+1][j][0];
        }
    }
    return 0;
}