#include<bits/stdc++.h>
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
			vector<vector<int>> e(n+1),son(n+1);
			for(int i=1;i<n;i++)
			{
				int u,v;
				cin>>u>>v;
				e[u].push_back(v);
				e[v].push_back(u);
			}
			vector<int> dep(n+1),vis(n+1),fa(n+1),cnt(n+1);
			queue<int> q;
			q.push(1);
			while(!q.empty())
			{
				int u=q.front();
				q.pop();
				if(vis[u]) continue;
				vis[u]=1;
				for(auto v:e[u])
				{
					if(vis[v]) fa[u]=v;
					else son[u].push_back(v),q.push(v),dep[v]=dep[u]+1;
				}
			}
			for(int i=1;i<=n;i++) cnt[dep[i]]++;
			int ans=0;
			for(auto tmp:cnt) ans=max(tmp,ans);
			//cout<<ans<<endl;
			for(int i=1;i<=n;i++) ans=max(ans,(int)son[i].size()+1);
			cout<<ans<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

