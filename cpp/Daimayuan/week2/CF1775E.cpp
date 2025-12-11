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
			int n;
			cin>>n;
			vector<int> a(n),prefix(n);
			int mipre=0x7fffffff,mxpre=0;
			for(auto &tmp:a) cin>>tmp;
			prefix[0]=a[0];
			for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+a[i];
			for(auto tmp:prefix) mipre=min(mipre,tmp),mxpre=max(mxpre,tmp);
			mipre=min(mipre,0ll);
			cout<<mxpre-mipre<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return Qaaxaap::work(),0;
}

