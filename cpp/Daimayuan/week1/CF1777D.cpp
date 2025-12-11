#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	const int N=5e5+5,mod=1e9+7;
	int qp(int d,int z)
	{
		int t=1;
		while(z)
		{
			if(z&1) t=t*d%mod;
			d=d*d%mod;
			z>>=1;
		}
		return t;
	}
	pair<int,int> dfs(int u,int f,vector<vector<int>> &g)
	{
		int mx=1,sum=0;
		for(auto v:g[u])
		{
			if(v==f) continue;
			pair<int,int> ret=dfs(v,u,g);
			mx=max(mx,1+ret.second);
			sum+=ret.first;
			sum%=mod;
		}
		sum+=mx;
		return {sum,mx};
	}
	void work()
	{
		int t;
		cin>>t;
		while(t--)
		{
			int n;
			cin>>n;
			vector<vector<int>> g(n+1);
			for(int i=1;i<n;i++)
			{
				int u,v;
				cin>>u>>v;
				g[v].push_back(u);
				g[u].push_back(v);
			}
			cout<<qp(2,n-1)*dfs(1,0,g).first%mod<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return Qaaxaap::work(),0;
}

