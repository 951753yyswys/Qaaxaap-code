#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace Qaaxaap
{
	const int N=5e5+5,mod=998244353,offset=100000;
	ll a[333],dp[2][200200];
	void work()
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		dp[1][a[3]+a[2]+offset]=dp[1][a[3]-a[2]+offset]=1;
		for(int i=1;i<n-2;i++)
		{
			for(int j=0;j<=200000;j++) dp[(i&1)^1][j]=0;
			for(int j=-90000;j<=90000;j++) 
			{
				dp[(i&1)^1][a[i+3]+j+offset]=(dp[(i&1)^1][a[i+3]+j+offset]+dp[i&1][j+offset])%mod;
				if(j==0) continue;
				dp[(i&1)^1][a[i+3]-j+offset]=(dp[(i&1)^1][a[i+3]-j+offset]+dp[i&1][j+offset])%mod;
			}
		}
		ll ans=0;
		for(int i=-90000;i<=90000;i++) ans=(ans+dp[(n-2)&1][i+offset])%mod;
		cout<<ans<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return Qaaxaap::work(),0;
}

