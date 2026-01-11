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
			vector<int> a(n);
			for(auto &tmp:a) cin>>tmp;
			if(a[0]==1||a[n-1]==1) cout<<"Alice"<<endl;
			else cout<<"Bob"<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

