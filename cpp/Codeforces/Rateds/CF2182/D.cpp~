#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	const int mod=998244353,M=55;
	int fac[M],fiv[M];
	int qp(int d,int z)
	{
		int t=1;
		while(z)
		{
			if(z&1) t=t*d%mod;
			d=d*d%mod;
			z>>=1;
		}
		return t;
	}
	int C(int n,int m)
	{
		if(m<0||m>n) return 0;
		return fac[n]*fiv[m]%mod*fiv[n-m]%mod;
	}
	void work()
	{
		fac[0]=fiv[0]=1;
		for(int i=1;i<M;i++) fac[i]=fac[i-1]*i%mod,fiv[i]=qp(fac[i],mod-2);
		int t;
		cin>>t;
		while(t--)
		{
			int n,sum=0;
			cin>>n;
			vector<int> a(n+1);
			for(auto &tmp:a) cin>>tmp,sum+=tmp;
			int q=sum/n,cnt=0,b=0,r=sum%n;
			for(int i=1;i<=n;i++) 
			{
				if(a[i]>q+1) cnt++;
				else if(a[i]==q+1) b++;
			}
			if(cnt>0||b>sum) 
			{
				cout<<0<<endl;
				continue;
			}
			int ans=C(n-b,r-b);
			ans=ans*fac[r]%mod*fac[n-r]%mod;
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

