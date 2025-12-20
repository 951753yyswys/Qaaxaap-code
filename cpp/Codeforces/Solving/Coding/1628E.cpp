#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	int fa[303030],v[303030],f[303030][30],dfn[303030],cnt,n,q;
	struct edge{int u,v,w;} e[303030];vector<vector<int>> son;
	bool cmp(edge x,edge y){return e[x].w<e[y].w;}
	int find(int x){if(fa[x]==x) return x;return fa[x]=find(fa[x]);}
	bool unite(int x,int y){x=find(x),y=find(y);return (x==y)?0:(1|(fa[x]=y));}
	void dfs(int u){dfn[u]=++cnt;for(auto v:son[u]) dfs(v);}
	struct seg{int l,r,tag};
	void work()
	{
		cin>>n>>q;son.resize(2*n);for(int i=1;i<n;i++) cin>>e[i].u>>e[i].v>>e[i].w;
		sort(e+1,e+n,cmp);int cn=n;for(int i=1;i<n*2;i++) fa[i]=i;
		for(int i=1;i<n;i++)
		{
			int fx=find(e[i].u),fy=find(e[i].v);
			if(fx==fy) continue;cn++;v[cn]=e[i].w;fa[fx]=fa[fy]=cn;
			son[cn].push_back(fx),son[cn].push_back(fy);if(cn==2*n-1) break;
		}
		for(int u=1;u<n*2;u++) for(auto v:son[u]) f[v][0]=u;
		for(int i=1;i<=25;i++) for(int j=1;j<2*n;j++) f[j][i]=f[f[j][i-1]][i-1];
		while(q--)
		{
			int opt;cin>>opt;
			
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

