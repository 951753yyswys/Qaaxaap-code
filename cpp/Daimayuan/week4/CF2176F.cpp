#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	const int N=305050,mod=998244353;
	int qp(int d,int z)
	{
		if(d<=0) return 0;
		int t=1;
		while(z)
		{
			if(z&1) t=t*d%mod;
			d=d*d%mod;
			z>>=1;
		}
		return t;
	}
	vector<int> pri;
	int mxp[N],ome[N];
	void pre(int n)
	{
		mxp[1]=1;
		for(int i=2;i<=n;i++)
		{
			if(!mxp[i]) 
			{
				mxp[i]=i;
				pri.push_back(i);
			}
			for(auto pri_j:pri)
			{
				if(i*pri_j>n) break;
				if(mxp[i*pri_j]==0) mxp[i*pri_j]=pri_j;
				if(i%pri_j==0) break;
			}
		}
	}
	void work()
	{
		pre(N-5050);
		for(int i=1;i<=N-6060;i++)
		{
			int lst=-1,x=i;
			while(x>1)
			{
				if(mxp[x]!=lst) ome[i]++,lst=mxp[x];
				x/=mxp[x];
			}
		}
		int t;
		cin>>t;
		while(t--)
		{
			int n,k,mx=0,ans=0;
			cin>>n>>k;
			vector<vector<int>> dp(n+1,vector<int>(20)),cnt(n+1,vector<int>(20));
			vector<int> a(n+1),cntt(n+1);
			for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,ome[a[i]]),cntt[a[i]]++;
			for(int i=1;i<=n;i++) for(int j=i;j<=n;j+=i) cnt[i][ome[j]]+=cntt[j];
			for(int i=1;i<=n;i++) for(int j=0;j<=mx;j++) for(int k=j;k<=mx;k++)
			{
				if(j!=k) dp[i][j+k]=(dp[i][j+k]+cnt[i][j]*cnt[i][k]%mod)%mod;
				else dp[i][j+k]=(dp[i][j+k]+(cnt[i][j]-1)*cnt[i][j]/2)%mod;
			}
			//for(int i=1;i<=n;i++) 
			//{
			//	cout<<"dp["<<i<<"]:";
			//	for(int j=0;j<=mx*2;j++) cout<<dp[i][j]<<' ';
			//	cout<<endl;
			//}
			for(int i=n;i>=1;i--) for(int j=i*2;j<=n;j+=i) for(int k=0;k<=mx*2;k++) dp[i][k]=(dp[i][k]-dp[j][k]+mod)%mod;
			for(int i=1;i<=n;i++) for(int j=0;j<=mx*2;j++) ans=(ans+dp[i][j]*qp(j-ome[i],k)%mod)%mod;
			//for(int i=1;i<=n;i++) 
			//{
			//	cout<<"dp["<<i<<"]:";
			//	for(int j=0;j<=mx*2;j++) cout<<dp[i][j]<<' ';
			//	cout<<endl;
			//}
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

