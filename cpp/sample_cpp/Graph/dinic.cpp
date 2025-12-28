#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Graph
{
	class graph_data
	{
	public:
		struct edge{int to,nxt,w;};
		int cnt=1;
		vector<edge> e;
		vector<int> dis,head;
		void add(int u,int v,int w)
		{
			cnt++;
			e[cnt].to=v;
			e[cnt].nxt=head[u];
			e[cnt].w=w;
			head[u]=cnt;
		}
		graph()=default;
	};
	class Dinic
	{
	public:
		graph_data &g;
		Dinic(graph_data&tmp):g(tmp){}
		int s,t;
		bool bfs()
		{		
			for(auto &tmp:g.dis) tmp=INT_MAX;
			queue<int> q;
			q.push(s);
			g.dis[s]=0;
			while(!q.empty())
			{
				int u=q.front();
				q.pop();
				for(int i=g.head[u];i;i=g.e[i].nxt)
				{
					int v=g.e[i].to;
					if(g.dis[v]!=INT_MAX||g.e[i].w==0) continue;
					g.dis[v]=g.dis[u]+1;
					q.push(v);
				}
			}
			return g.dis[t]^INT_MAX; 
		}
		int dfs(int u,int w)
		{
			if(u==t) return w;
			int ret=0;
			for(int &i=g.head[u];i&&w;i=g.e[i].nxt)
			{
				int v=g.e[i].to;
				if(g.dis[v]==g.dis[u]+1&&g.e[i].w)
				{
					g.head[u]=i;
					int f=dfs(v,min(w,g.e[i].w));
					g.e[i].w-=f;
					g.e[i^1].w+=f;
					w-=f;
					ret+=f;
					if(w==0) break; 
					if(f==0) g.dis[v]=INT_MAX;
				}
			}
			return ret;
		}
		int work(int S,int T)
		{
			s=S;
			t=T;
			int ret=0;
			vector<int> now=g.head;
			while(bfs())
			{
				ret+=dfs(s,INT_MAX);
				g.head=now;
			}
			return ret;
		}
	};
	class graph 
	{
	public:
		graph_data g;
		int dinic(int s,int t)
		{
			return Dinic(g).work(s,t);
		}
	};
}
namespace Qaaxaap
{
	const int N=5e5;
	
	void work()
	{
		int n,m,S,T;
		cin>>n>>m>>S>>T;
		dis.resize(n+1);
		head.assign(n+3,0);
		for(int i=1;i<=m;i++) 
		{
			int u,v,w;
			cin>>u>>v>>w;
			add(u,v,w);
			add(v,u,0);
		}
		s=S;
		t=T;
		cout<<dinic();
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}
