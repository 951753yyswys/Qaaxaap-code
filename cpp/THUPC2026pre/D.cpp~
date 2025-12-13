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
			vector<int> x(n),ans(n);
			for(auto &tmp:x) cin>>tmp;
			sort(x.begin(),x.end());
			int mx=0,ami=(n-1)/2,amx=ami;
			ans[ami]=x[mx++];
			while(ami>0&&amx<n-1)
			{
				ans[++amx]=x[mx++];
				ans[--ami]=x[mx++];
			}
			while(amx<n-1) ans[++amx]=x[mx++];
			while(ami>0) ans[--ami]=x[mx++];
			int lans=0;
			for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) lans+=(j-i)*ans[i]*ans[j];
			cout<<lans;
			cout<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return Qaaxaap::work(),0;
}

