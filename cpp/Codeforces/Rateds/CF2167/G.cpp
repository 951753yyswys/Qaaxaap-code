#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);    
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        vector<int> a(n),c(n),dp(n);
        int sumc=0,msum=-0x7ffffffffff;
        for(auto &tmp:a) cin>>tmp;
        for(auto &tmp:c) cin>>tmp,sumc+=tmp;
        for(int i=0;i<n;i++) 
        {
            dp[i]=c[i]; 
            for(int j=0;j<i;j++) 
                if(a[j]<=a[i]) 
                    dp[i]=max(dp[i],dp[j]+c[i]);
            msum=max(msum,dp[i]);
        }
        int ans=sumc-msum;
        cout<<ans<<"\n";
    }
    
    return 0;
}