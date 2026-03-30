#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[5050];
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n),num(n+1);
        for(int i=0;i<n;i++) 
        {
            cin>>a[i];
            if(a[i]<=n) num[a[i]]++;
        }
        int mex=0;
        while(num[mex]>0) mex++;
        //cout<<"mex:"<<mex<<endl;
        for(int i=0;i<mex;i++) dp[i]=1e9;
        dp[mex]=0;
        for(int j=mex;j>=0;j--) for(int i=j-1;i>=0;i--)
        {
            dp[i]=min(dp[i],dp[j]+(num[i]-1)*j+i);
        }
        cout<<dp[0]<<endl;
    }
    return 0;
}