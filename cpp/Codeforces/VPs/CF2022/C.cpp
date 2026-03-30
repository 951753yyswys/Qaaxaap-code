// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int dp[101010][10];
// signed main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0),cout.tie(0);
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n;
//         cin>>n;
//         string s,t;
//         cin>>s>>t;
//         s='#'+s;
//         t='#'+t;
//         for(int i=0;i<=n;i++) dp[i][0]=dp[i][1]=0;
//         for(int i=2;i<=n;i++)
//         {
//             if(i%3==1) 
//             {
//                 int cnt=0;
//                 if(s[i]=='A') cnt++;
//                 if(s[i-1]=='A') cnt++;
//                 if(s[i-2]=='A') cnt++;
//                 dp[i][0]=dp[i-2][1]+cnt/2;
//                 cnt=0;
//                 if(t[i]=='A') cnt++;
//                 if(t[i-1]=='A') cnt++;
//                 if(t[i-2]=='A') cnt++;
//                 dp[i][1]=dp[i-2][0]+cnt/2;
//             }
//             if(i%3==2)
//             {
//                 int cnt=0;
//                 if(s[i]=='A') cnt++;
//                 if(s[i-1]=='A') cnt++;
//                 if(t[i-1]=='A') cnt++;
//                 dp[i][0]=max(dp[i-2][0],dp[i-2][1])+cnt/2;
//                 cnt=0;
//                 if(s[i]=='A') cnt++;
//                 if(s[i-1]=='A') cnt++;
//                 if(s[i-2]=='A') cnt++;
//                 dp[i][0]=max(dp[i][0],dp[i-2][0]+cnt/2);
//                 cnt=0;
//                 if(t[i]=='A') cnt++;
//                 if(t[i-1]=='A') cnt++;
//                 if(s[i-1]=='A') cnt++;
//                 dp[i][1]=max(dp[i-2][1],dp[i-2][0])+cnt/2;
//                 cnt=0;
//                 if(t[i]=='A') cnt++;
//                 if(t[i-1]=='A') cnt++;
//                 if(t[i-2]=='A') cnt++;
//                 dp[i][1]=max(dp[i][1],dp[i-2][1]+cnt/2);
//             }
//             if(i%3==0)
//             {
//                 int cnt=0;
//                 if(s[i]=='A') cnt++;
//                 if(s[i-1]=='A') cnt++;
//                 if(s[i-2]=='A') cnt++;
//                 dp[i][1]=dp[i-3]
//             }
//         }
//     }
//     return 0;
// } 