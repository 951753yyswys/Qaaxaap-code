#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace DS
{
	class phitree
	{
	public:
		vector<int> dep,fa;
		vector<vector<int>> son;
		phitree(){dep.resize(5050505),fa.resize(5050505),son.resize(5050505);}
		void init(vector<int>& a,int * phi) 
		{
			//for(int i=1;i<=10;i++) cout<<phi[i]<<' ';
			cout<<endl;
			vector<int> b=a;
			sort(b.begin(),b.end());
			fa[1]=1;
			for(auto tmp:b) while(fa[tmp]==0) 
					fa[tmp]=phi[tmp],son[fa[tmp]].push_back(tmp),tmp=fa[tmp];
			dep[1]=1;
			queue<int> q;
			q.push(1);
			while(!q.empty())
			{
				int u=q.front();
				q.pop();
				for(auto tmp:son[u]) dep[tmp]=dep[u]+1,q.push(tmp);
			}
		}
		int lca(int x,int y)
		{
			if(dep[x]<dep[y]) swap(x,y);
			while(dep[x]>dep[y]) x=fa[x];
			while(x!=y) x=fa[x],y=fa[y];
			return x;
		}
		int updlca(int upd,int old)
		{
			if(dep[upd]>=dep[old]) return old;
			return upd;
		}
		int updlca(int upd,int ol1,int ol2)
		{
			if(dep[ol1]>dep[ol2]) swap(ol1,ol2);
			if(dep[upd]>=dep[ol1]) return ol1;
			return upd;
		}
		int kfa(int x,int k)
		{
			for(int i=1;i<=k;i++)
			{
				if(x==1) return 1;
				x=fa[x];
			}
			return x;
		}
		int cd(int x,int fx)
		{
			return abs(dep[x]-dep[fx]);
		}
		void prit()
		{
			cout<<"print phitree:"<<endl;
			queue<int> q;
			q.push(1);
			while(!q.empty())
			{
				int u=q.front();
				cout<<"an edge from "<<fa[u]<<" to "<<u<<endl;
				q.pop();
				for(auto tmp:son[u]) dep[tmp]=dep[u]+1,q.push(tmp);
			}
			cout<<"end!"<<endl;
		}
		int depth(int x){return dep[x];}
	};	
	class seg
	{
	public:
		struct tree
		{
			int l,r,lca,ans,siz,sum;
		};
		vector<tree> t; 
		seg(){t.resize(505050);}
		phitree b;
		int n;
		void init(vector<int> &a,int* phi)
		{
			n=a.size();
			b.init(a,phi);
			//b.prit();
			build(1,1,n,a);
		}
		void build(int ro,int l,int r,vector<int> &a)
		{
			int mid=l+r>>1;
			t[ro].l=l;
			t[ro].r=r;
			if(l==r)
			{
				t[ro].lca=a[l-1];
				t[ro].siz=(a[l-1]!=1);
				t[ro].sum=b.depth(t[ro].lca);
				return;
			}
			build(ro<<1,l,mid,a);
			build(ro<<1|1,mid+1,r,a);
			t[ro].lca=b.lca(t[ro<<1].lca,t[ro<<1|1].lca);
			t[ro].siz=t[ro<<1].siz+t[ro<<1|1].siz;
			t[ro].sum=t[ro<<1].sum+t[ro<<1|1].sum;
		}
		void update(int ro,int l,int r)
		{
			if(t[ro].siz==0) return;
			if(t[ro].l==t[ro].r) 
			{
				t[ro].lca=b.kfa(t[ro].lca,1);
				t[ro].sum=b.depth(t[ro].lca);
				t[ro].siz=(t[ro].lca!=1);
				return;
			}
			if(t[ro<<1].r>=l) update(ro<<1,l,r);
			if(t[ro<<1|1].l<=r) update(ro<<1|1,l,r);
			t[ro].lca=b.updlca(t[ro].lca,t[ro<<1].lca,t[ro<<1|1].lca);
			t[ro].sum=t[ro<<1].sum+t[ro<<1|1].sum;
			t[ro].siz=t[ro<<1].siz+t[ro<<1|1].siz;
		}
		pair<int,int> query(int ro,int l,int r)
		{
			if(t[ro].l>=l&&t[ro].r<=r)
				return {t[ro].lca,t[ro].sum};
			pair<int,int> ansl={-1,-1},ansr={-1,-1};
			if(t[ro<<1].r>=l) ansl=query(ro<<1,l,r);
			if(t[ro<<1|1].l<=r) ansr=query(ro<<1|1,l,r);
			pair<int,int> ans;
			if(ansl.second!=-1&&ansr.second!=-1) ans.first=b.lca(ansl.first,ansr.first),ans.second=ansl.second+ansr.second;
			else ans.first=max(ansl.first,ansr.first),ans.second=max(ansl.second,ansr.second);
			return ans;
		}
		int query(int l,int r)
		{
			pair<int,int> ret=query(1,l,r);
			return ret.second-b.depth(ret.first)*(r-l+1);
		}
		void prit()
		{
			cout<<"print seg:"<<endl;
			for(int i=1;i<=n*4;i++)
			{
				cout<<"ro:"<<i<<" lt:"<<t[i].l<<" rt:"<<t[i].r<<" lca:"<<t[i].lca<<" sum:"<<t[i].sum<<endl;
			}
			cout<<"end!"<<endl;
		}
	};
}
using namespace DS;
//namespace Qaaxaap
//{
	const int N=6e6+101,mod=998244353;
	int a[101010];
	vector<int> pri;
	bool not_prime[N];
	int phi[N];
	void pre(int n) 
	{
		phi[1] = 1;
		for (int i = 2; i <= n; i++) 
		{
			if (!not_prime[i]) 
			{
				pri.push_back(i);
				phi[i] = i - 1;
			}
			for (int pri_j : pri) 
			{
				if (i * pri_j > n) break;
				not_prime[i * pri_j] = true;
				if (i % pri_j == 0) 
				{
					phi[i * pri_j] = phi[i] * pri_j;
					break;
				}
				phi[i * pri_j] = phi[i] * phi[pri_j];
			}
		}
	}
	void work()
	{
		//cout << "zjr" << endl;
		pre(5000005);
		int n,m;
		cin>>n>>m;
		vector<int> a(n);
		for(auto &tmp:a) cin>>tmp;
		seg dzd;
		dzd.init(a,phi);
		//dzd.prit();
		while(m--)
		{
			int opt,l,r;
			cin>>opt>>l>>r;
			if(opt==1)
			{
				dzd.update(1,l,r);
			}
			if(opt==2)
			{
				cout<<dzd.query(l,r)<<endl;
			}
			//dzd.prit();
		}
	}
//}
signed main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0),cout.tie(0);
	work();
	//return Qaaxaap::work(),0;
}

