#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	void work()
	{
		int n;
		cin>>n;
		vector<vector<int>> g(n+1);
		for(int i=1;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			g[a].emplace_back(b);
			g[b].emplace_back(a);
		}
		vector<int> dis(n+1),has(n+1),fa(n+1);
		queue<int> q;
		q.push(1);
		dis[1]=1;
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(auto v:g[u]) 
			{
				if(dis[v]) continue;
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
		int mx1=max_element(dis.begin(),dis.end())-dis.begin();
		dis.assign(n+1,0);
		q.push(mx1);
		dis[mx1]=1;
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(auto v:g[u]) 
			{
				if(dis[v]) continue;
				dis[v]=dis[u]+1;
				fa[v]=u;
				q.push(v);
			}
		}
		int mx2=max_element(dis.begin(),dis.end())-dis.begin();
		int now=mx2;
		while(now) has[now]=1,now=fa[now];
		stack<pair<int,int>> st;
		st.push({mx1,0});
		vector<int> ans(n+1);
		now=0;
		//cout<<mx1<<endl;
		//for(auto &tmp:fa) cout<<tmp<<' ';
		while(!st.empty())
		{
			auto [u,sta]=st.top();
			//cout<<u<<' '<<sta<<endl;
			st.pop();
			++now;
			if(!sta)
			{
				ans[u]=now;
				int hs=0;
				st.push({u,1});
				for(auto v:g[u]) 
				{
					if(v==fa[u]) continue;
					if(has[v])
					{
						hs=v;
						break;
					}	
				}
				if(hs) st.push({hs,0});
				for(auto v:g[u])
				{
					if(v==fa[u]||hs==v) continue;
					else st.push({v,0});
				}	
			}
		}		
		for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
	}
}
signed main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

