#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	const int mod=998244353;
	int slowp(int d,int z)
	{
		int t=1,sum=0;
		d%=mod;
		for(int i=1;i<=z;i++)
		{
			t=t*d%mod;
			sum=(sum+t)%mod;
		}
		return sum;
	}
	vector<int> pri;
	int npri[505050];
	void init(int x)
	{
		npri[1]=1;
		for(int i=1;i<=x;i++)
		{
			if(!npri[i]) pri.emplace_back(i);
			for(auto pri_j:pri)
			{
				if(i*pri_j>x) break;
				npri[i*pri_j]=1;
				if(i%pri_j==0) break;
			}
		}
	}
	void work()
	{
		init(500000);
		int n,m;
		cin>>n>>m;
		int ans=slowp(m,n);
		int np=1,cm=1,ed=0,sm=0;
		for(int i=1;i<=n;i++)
		{
			if(pri[ed]<=i) cm*=pri[ed],ed++;
			if(cm>m) 
			{
				np=0;
				break;
			}
			np=np*((m/cm)%mod)%mod;
			sm=(sm+np)%mod;
		}
		cout<<(ans-sm+mod)%mod;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

