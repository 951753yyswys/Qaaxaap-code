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
			vector<int> a(n),suf(n+2),pre(n+1);
			for(auto &tmp:a) cin>>tmp;
			int ans=LLONG_MIN;
			pre[1]=a[0];
			suf[n]=-a[n-1];
			for(int i=2;i<=n;i++) pre[i]=pre[i-1]+abs(a[i-1]);
			for(int i=n-1;i>0;i--) suf[i]=suf[i+1]-a[i-1];
			for(int i=1;i<=n;i++) ans=max(ans,pre[i-1]+suf[i+1]);
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

