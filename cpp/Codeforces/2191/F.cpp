#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace DS 
{
	class DSU 
	{
	public:
		int n;
		vector<int> p,sz;
		DSU(int n=0):n(n),p(n+1),sz(n+1,1) {iota(p.begin(),p.end(),0);}
		int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
		void unite(int a,int b)
		{
			a=find(a);b=find(b);
			if(a==b) return;
			if(sz[a]<sz[b]) swap(a,b);
			p[b]=a;sz[a]+=sz[b];
		}
	};
}
using namespace DS;
namespace Qaaxaap
{
	const int mod=998244353;
	int qp(int d,int z) 
	{
		int t=1;
		d%=mod;
		while(z>0) 
		{
			if(z&1) t=(t*d)%mod;
			d=(d*d)%mod;
			z>>=1;
		}
		return t;
	}
	int invp(int a) {return qp(a,mod-2);}
	void work()
	{
		int t;
		cin>>t;
		while(t--) 
		{
			int n,m;
			cin>>n>>m;
			vector<vector<int>> adj(n+1);
			DSU dsu(n);
			for(int i=0;i<m;i++) 
			{
				int u,v;cin>>u>>v;
				adj[u].push_back(v);
				adj[v].push_back(u);
				dsu.unite(u,v);
			}
			vector<int> cp(n+1);
			map<int,int> id;
			vector<int> cmr;
			for(int i=1;i<=n;i++)
			{
				int r=dsu.find(i);
				auto it=id.find(r);
				if(it==id.end()){
					int nid=id.size();
					id[r]=nid;
					cmr.push_back(r);
				}
				cp[i]=id[r];
			}
			int k=id.size();
			vector<int> s(k,0);
			for(int r:cmr) s[id[r]]=dsu.sz[dsu.find(r)];
			int cma=cp[n];
			int cmb=cp[n-1];
			int p=1;
			for(int i=0;i<k;i++) p=(p*s[i])%mod;
			vector<int> ans(n+1,0);
			auto nig=[&](int tg)->int
			{
				vector<int> pa(n+1,-1);
				pa[n]=0;
				vector<int> st;
				st.push_back(n);
				while(!st.empty())
				{
					int u=st.back();st.pop_back();
					for(int v:adj[u])
					{
						if(pa[v]!=-1) continue;
						if(cp[v]!=cma) continue;
						pa[v]=u;
						st.push_back(v);
					}
				}
				int now=tg;
				while(pa[now]!=n) now=pa[now];
				return now;
			};
			if(k==1) 
			{
				int v0=nig(n-1);
				ans[v0]=1;
			} 
			else if(cma==cmb) 
			{
				int v0=nig(n-1);
				int tot=qp(n,k-2)*p%mod;
				ans[v0]=tot;
			}
			else
			{
				int invsa=invp(s[cma]);
				int pk2=qp(n,k-2);
				vector<int> pa(n+1,-1);
				vector<int> ord;
				pa[n]=0;
				vector<int> st;
				st.push_back(n);
				while(!st.empty())
				{
					int u=st.back();st.pop_back();
					ord.push_back(u);
					for(int v:adj[u])
					{
						if(pa[v]!=-1) continue;
						if(cp[v]!=cma) continue;
						pa[v]=u;
						st.push_back(v);
					}
				}
				vector<int> sub(n+1,0);
				for(int i=ord.size()-1;i>=0;i--)
				{
					int u=ord[i];
					int sum=1;
					for(int v:adj[u])
					{
						if(cp[v]!=cma) continue;
						if(pa[v]==u) sum+=sub[v];
					}
					sub[u]=sum;
				}
				int tmp=p*invsa%mod*pk2%mod;
				for(int v:adj[n])
				{
					if(cp[v]!=cma) continue;
					if(pa[v]==n) ans[v]=tmp*sub[v]%mod;
				}
				vector<int> g(k,0);
				if(k==2) g[cmb]=1;
				else 
				{
					int bs=p*qp(n,k-3)%mod;
					int sa=s[cma];
					int sb=s[cmb];
					for(int c=0;c<k;c++)
					{
						if(c==cma) continue;
						int f;
						if(c==cmb) f=bs*((sa+sb)%mod)%mod;
						else f=bs*s[c]%mod;
						int invsc=invp(s[c]);
						g[c]=f*invsa%mod*invsc%mod;
					}
				}
				for(int v=1;v<=n-1;v++) if(cp[v]!=cma) ans[v]=g[cp[v]];
			}
			for(int v=1;v<=n-1;v++) cout<<ans[v]%mod<<' ';
			cout<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

