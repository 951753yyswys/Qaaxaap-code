#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	const int N=5e5+5,mod=998244353;
	void work()
	{
		int n;
		cin>>n;
		vector<int> a(n+2),pre(n+2),suf(n+2);
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) pre[i]=max(pre[i-1],a[i]+n-i);
		for(int i=n;i>=1;i--) suf[i]=max(suf[i+1],a[i]+i-1);
		int ans=0x7fffffffffffff;
		for(int i=1;i<=n;i++) ans=min(ans,max({pre[i-1],suf[i+1],a[i]}));
		cout<<ans;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return Qaaxaap::work(),0;
}

