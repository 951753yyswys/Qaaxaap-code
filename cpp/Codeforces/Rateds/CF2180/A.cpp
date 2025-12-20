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
			int a,b,l;
			cin>>l>>a>>b;
			b%=l;
			if(b==0) cout<<a%l<<endl;
			else cout<<((l-a)%l)/b*b+a<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

