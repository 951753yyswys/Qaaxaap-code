#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	void work()
	{
		int t;
		cin>>t;
		while(t--)
		{
			int n;
			cin>>n;
            int len=min(500ll,2*(int)(sqrt(n))+4);
			vector<vector<int>> dp(n+2,vector<int>(len,INT_MIN));
			vector<int> a(n+2),sum(n+2);
			for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
			for(int i=n;i>=1;i--) 
			{
				dp[i][1]=max(a[i],dp[i+1][1]);
				for(int j=2;j*(j+1)/2<=n-i+1;j++) dp[i][j]=max(dp[i+1][j],(dp[i+j][j-1]>sum[i+j-1]-sum[i-1])*(sum[i+j-1]-sum[i-1]));	
			}
			int ans=0;
			for(int i=1;i<len;i++) if(dp[1][i]>0) ans=i;
			cout<<ans<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}


