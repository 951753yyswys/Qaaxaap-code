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
			vector<vector<int>> e(n+1),son(n+1),cnt(n+1);
			for(int i=1;i<n;i++)
			{
				int u,v;
				cin>>u>>v;
				e[u].push_back(v);
				e[v].push_back(u);
			}
			vector<int> dep(n+1),vis(n+1),fa(n+1),col(n+1),ban(n+1);
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
			for(int i=1;i<=n;i++) cnt[dep[i]].push_back(i);
			int ans=0;
			for(int i=0;i<=n;i++) ans=max((int)cnt[i].size(),ans);
			//cout<<ans<<endl;
			for(int i=1;i<=n;i++) ans=max(ans,(int)son[i].size()+1);
			cout<<ans<<endl;
			vector<vector<int>> out(ans+1);
			col[1]=1;
			//for(int i=1;i<=n;i++) cout<<' '<<dep[i];
			//cout<<endl;
			for(int i=1;i<=n;i++)
			{
				if(cnt[i].empty()) continue;
				bool flag=0;
				int lst=cnt[i][0];
				for(auto u:cnt[i])
				{
					ban[u]=col[fa[u]];
					if(ban[u]!=ban[lst]) flag=1;
					lst=u;
				}
				if(cnt[i].size()==1) flag=0;
				if(flag)
				{
					vector<int> bad;
					for(int j=0;j<cnt[i].size();j++) 
					{
						int u=cnt[i][j];
						col[u]=j+1;
						if(ban[u]==col[u]) bad.push_back(u);
					}
					if(bad.size()==0) continue;
					if(bad.size()==1)
					{
						int bd=bad[0];
						for(auto u:cnt[i])
						{
							if(u==bd) continue;
							if(ban[u]!=col[bd]) 
							{
								swap(col[u],col[bd]);
								break;
							}
						}
						continue;
					}
					int yys=col[bad[0]];
					for(int j=1;j<bad.size();j++) col[bad[j-1]]=col[bad[j]];
					col[*prev(bad.end())]=yys;
				}	
				else 
				{
					int bc=ban[cnt[i][0]],ys=0;
					//cout<<' '<<bc;
					for(auto u:cnt[i]) 
					{
						//cout<<u<<' ';
						ys++;
						if(ys==bc) ys++;
						col[u]=ys;
					}
					//cout<<endl;
				}
			}
			for(int i=1;i<=n;i++) out[col[i]].push_back(i);
			for(int i=1;i<=ans;i++)
			{
				cout<<out[i].size()<<" ";
				for(auto tmp:out[i]) cout<<tmp<<" ";
				cout<<endl;
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

