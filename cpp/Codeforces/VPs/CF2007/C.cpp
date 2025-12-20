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
			int n,a,b,ans=0x7ffffffffffff;
			cin>>n>>a>>b;
			int g=__gcd(a,b);
			vector<int> v(n);
			for(auto &tmp:v){cin>>tmp,tmp=tmp%g;}
			sort(v.begin(),v.end());
			v.resize(n*2);
			for(int i=0;i<n;i++) v[i+n]=v[i]+g;
			for(int i=0;i<n;i++) ans=min(ans,v[i+n-1]-v[i]);
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

