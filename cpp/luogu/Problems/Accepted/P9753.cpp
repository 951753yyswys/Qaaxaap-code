// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// signed main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0),cout.tie(0);
//     int n;
//     int ans=0;
//     cin>>n;
//     vector<int> a(n+1,0),dp(n+1,0);
//     stack<pair<char,int>> st;
//     string s;
//     cin>>s;
//     s='#'+s;
//     for(int i=1;i<=n;i++)
//     {
//         if(st.empty()) 
//         {
//             st.push({s[i],i});
//             continue;
//         }
//         if(s[i]==st.top().first)
//         {
//             dp[i]=1+dp[st.top().second-1];
//             //dp[i]=1+dp[i-1];
//             ans+=dp[i];
//             st.pop();
//             continue;
//         }
//         //dp[i]=1+dp[i-1];
//         st.push({s[i],i});
//     }
//     cout<<ans<<endl;
//     //for(auto tmp:dp) cout<<tmp<<' ';
//     return 0;
// } 
// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // signed main()
// // {
// //     ios::sync_with_stdio(0);
// //     cin.tie(0),cout.tie(0);
// //     int n;
// //     cin>>n;
// //     vector<int> a(n),dp(n);
// //     string s;
// //     cin>>s;

// //     return 0;
// // } 
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    s='#'+s;
    vector<int> flag(n+1,0),dp(n+1,0);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;j>0;j=flag[j]-1)
        {
            if(s[i]==s[j]) 
            {
                flag[i]=j;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!flag[i]) continue;
        dp[i]=1+dp[flag[i]-1];
        ans+=dp[i];
    }
    cout<<ans;
    return 0;
} 