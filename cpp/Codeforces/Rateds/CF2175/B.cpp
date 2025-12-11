#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	const int N=5e5+5,mod=998244353;
	void work()
	{
		int t;
		cin>>t;
		while(t--)
		{
			int n,l,r;
			cin>>n>>l>>r;
			vector<int> a(n+1),x(n+1);
			int cnt=0,cntr=0;
			for(int i=1;i<l;i++) x[i]=++cnt;
			for(int i=r+1;i<=n;i++) x[i]=++cnt;
			for(int i=l;i<r;i++) x[i]=++cnt;
			x[r]=x[l-1];
			for(int i=1;i<=n;i++) a[i]=x[i-1]^x[i];
			for(int i=1;i<=n;i++) cout<<a[i]<<' ';
			cout<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return Qaaxaap::work(),0;
}

