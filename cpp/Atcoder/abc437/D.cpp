#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	const int mod=998244353;
	void work()
	{
		int n,m;
		cin>>n>>m;
		vector<int> a(n+1),b(m+1),pre(m+1),suf(m+2);
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=m;i++) cin>>b[i];
		sort(next(b.begin()),b.end());
		sort(next(a.begin()),a.end());
		for(int i=m;i>0;i--) suf[i]=suf[i+1]+b[i],suf[i]%=mod;
		for(int i=1;i<=m;i++) pre[i]=pre[i-1]+b[i],pre[i]%=mod;
		int ans=0,j=1;
		for(int i=1;i<=n;i++)
		{
			while(j<=m&&b[j]<a[i]) j++;
			ans+=a[i]*(j-1)%mod-pre[j-1]+mod;
			ans%=mod;
			ans+=suf[j]-(m-j+1)*a[i]%mod+mod;
			ans%=mod;
		}
		cout<<ans;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}
