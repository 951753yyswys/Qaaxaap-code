#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	void work()
	{
		int n,m;
		cin>>n>>m;
		int ans=0x7fffffff,lt=0;
		string s,t;
		cin>>s>>t;
		s='+'+s;
		t='+'+t;
		for(int i=1;i+m-1<=n;i++)
		{
			lt=0;
			for(int j=1;j<=m;j++) lt+=(s[i+j-1]-t[j]+10)%10;
			ans=min(ans,lt);
		}
		cout<<ans;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

