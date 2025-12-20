#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	void work()
	{
		int h,w,n;
		cin>>h>>w>>n;
		vector<set<int>> mp(h+1);
		for(int i=1;i<=h;i++) for(int j=1;j<=w;j++)
		{
			int tmp;
			cin>>tmp;
			mp[i].insert(tmp);
		}
		int ans=0;
		vector<int> b(n);
		for(auto &tmp:b) cin>>tmp;
		for(int i=1;i<=h;i++)
		{
			int ansl=0;
			for(int j=0;j<n;j++) ansl+=mp[i].count(b[j]);
			ans=max(ans,ansl);
		}
		cout<<ans<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

