#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int main() 
{
    int n,l,k;
    string s;
    cin>>n>>l>>k>>s;
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(26,INF)));
    for(int c=0;c<26;c++) dp[0][0][c]=0;
    for(int i=0;i<n;i++) for(int j=0;j<=k;j++) for(int lsc=0;lsc<26;lsc++) 
    {
        if(dp[i][j][lsc]==INF) continue;
        int nc=s[i]-'a';
        int nej=(i==0)?1:j+(nc!=lsc);
        if(nej<=k) dp[i+1][nej][nc]=min(dp[i+1][nej][nc],dp[i][j][lsc]);
        for(int len=1;len<=l&&i+len<=n;len++) 
        {
            int cost=dp[i][j][lsc]+1;
            vector<int> tmp;
            if(i>0) tmp.push_back(lsc);
            tmp.push_back(nc);  
            sort(tmp.begin(),tmp.end());
            tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
            for(int nec:tmp) 
            {
                int tmp2=(i==0)?1:j+(nec!=lsc);
                if(tmp2<=k) dp[i+len][tmp2][nec]=min(dp[i+len][tmp2][nec],cost);
            }
        }
    }
    int ans=INF;
    for(int j=1;j<=k;j++) for(int c=0;c<26;c++) ans=min(ans,dp[n][j][c]);
    cout<<ans;
    return 0;
}