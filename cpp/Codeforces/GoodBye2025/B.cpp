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
			string s;
			cin>>s;
			int n=s.size();
			s='+'+s;
			vector<int> dp0(n+1,INT_MAX),dp1(n+1,INT_MAX);
			if(s[1]=='s') dp1[1]=0;
			else dp1[1]=1;
			for(int i=2;i<=n;i++)
			{
				if(s[i]=='s') dp1[i]=min(dp0[i-1],dp1[i-1]);
				else dp0[i]=dp1[i-1],dp1[i]=1+min(dp0[i-1],dp1[i-1]);
			}
			cout<<dp1[n]<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

