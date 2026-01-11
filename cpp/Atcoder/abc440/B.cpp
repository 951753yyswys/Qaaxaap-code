#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	void work()
	{
		int n;
		cin>>n;
		vector<int> a(n),b(n);
		iota(b.begin(),b.end(),0);
		for(auto &tmp:a) cin>>tmp;
		sort(b.begin(),b.end(),[&](int x,int y){return a[x]<a[y];});
		cout<<b[0]+1<<' '<<b[1]+1<<' '<<b[2]+1;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

