#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	int n,m,l;
	int s,t;
	vector<vector<pair<int,int>>> g;
	vector<bool> ok;
	void dfs(int u,int st,int sum) 
	{
		if(sum>t) return;    
		if(st==l) 
		{
			if(s<=sum&&sum<=t) ok[u]=1;
			return;
		}
		for(auto [v,w]:g[u]) dfs(v,st+1,sum+w);
	}
	void work()
	{
		cin>>n>>m>>l>>s>>t;
		g.resize(n+1);
		ok.assign(n+1,0);
		for(int i=0;i<m;i++) 
		{
			int u,v,c;
			cin>>u>>v>>c;
			g[u].push_back({v,c});
		}
		dfs(1,0,0);
		bool fis=1;
		for(int i=1;i<=n;i++) 
		{
			if(ok[i]) 
			{
				if(!fis) cout<<' ';
				cout<<i;
				fis=0;
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

