#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	void work()
	{
		int n,m;
		cin>>n>>m;
		vector<int> r(n+1);
		for(int i=1;i<=n;i++) cin>>r[i];
		while(m--)
		{
			int p,d;
			string sta;
			cin>>p>>d>>sta;
			if(sta=="Closed") continue;
			r[p]=d;
		}
		for(int i=1;i<=n;i++) cout<<r[i]<<' ';
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

