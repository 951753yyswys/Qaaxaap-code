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
			int n,k;
			cin>>n>>k;
			vector<int> p(n),d(n);
			for(auto &tmp:p) cin>>tmp;
			for(auto &tmp:d) cin>>tmp;
			map<int,vector<int>> zb,fb;
			for(int i=0;i<n;i++)
			{
				zb[(p[i]-d[i])%k].push_back(i);
				fb[(p[i]+d[i])%k].push_back(i);
			}
			
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

