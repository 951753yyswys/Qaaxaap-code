#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	void work()
	{
		int p,q,x,y;
		cin>>p>>q>>x>>y;
		if(y>=q&&x>=p&&y<q+100&&x<p+100) cout<<"Yes";
		else cout<<"No";
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

