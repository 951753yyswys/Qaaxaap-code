#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=LLONG_MIN;
namespace DS
{
	class SegTree 
	{
	public:
		struct node 
		{
			int mxup=0,mxdn=INF;
			int adup=0,add_down=0;
			int cnup=0,cndown=0;
			bool flip=0;
			bool set0=0;
		};
		int n;
		vector<node> st;
		SegTree(int n):n(n),st(4*n+5){build(1,1,n);}
		void build(int p,int l,int r) 
		{
			st[p].flip=0;
			st[p].set0=0;
			st[p].adup=st[p].add_down=0;
			if(l==r) 
			{
				st[p].cnup=1;
				st[p].cndown=0;
				st[p].mxup=0;
				st[p].mxdn=INF;
				return;
			}
			int mid=l+r>>1;
			build(p<<1,l,mid);
			build(p<<1|1,mid+1,r);
			pushup(p);
		}
		void pushup(int p) 
		{
			auto &a=st[p<<1];
			auto &b=st[p<<1|1];
			st[p].cnup=a.cnup+b.cnup;
			st[p].cndown=a.cndown+b.cndown;
			st[p].mxup=max(a.mxup,b.mxup);
			st[p].mxdn=max(a.mxdn,b.mxdn);
		}
		void as0(int p) 
		{
			st[p].set0=1;
			st[p].adup=st[p].add_down=0;
			st[p].mxup=(st[p].cnup?0:INF);
			st[p].mxdn=(st[p].cndown?0:INF);
		}
		void afl(int p) 
		{
			st[p].flip^=1;
			swap(st[p].cnup,st[p].cndown);
			swap(st[p].mxup,st[p].mxdn);
			swap(st[p].adup,st[p].add_down);
		}
		void aau(int p,int x) 
		{
			if(st[p].cnup) st[p].mxup+=x;
			st[p].adup+=x;
		}
		void aad(int p,int x) 
		{
			if(st[p].cndown) st[p].mxdn+=x;
			st[p].add_down+=x;
		}
		void pushdown(int p)
		{
			if(st[p].set0) 
			{
				as0(p<<1);
				as0(p<<1|1);
				st[p].set0=0;
			}
			if(st[p].flip) 
			{
				afl(p<<1);
				afl(p<<1|1);
				st[p].flip=0;
			}
			if(st[p].adup!=0) 
			{
				aau(p<<1,st[p].adup);
				aau(p<<1|1,st[p].adup);
				st[p].adup=0;
			}
			if(st[p].add_down!=0) 
			{
				aad(p<<1,st[p].add_down);
				aad(p<<1|1,st[p].add_down);
				st[p].add_down=0;
			}
		}
		void rau(int p,int l,int r,int lt,int rt,int x) 
		{
			if(rt<l||r<lt) return;
			if(lt<=l&&r<=rt) 
			{
				aau(p,x);
				return;
			}
			pushdown(p);
			int m=(l+r)>>1;
			rau(p<<1,l,m,lt,rt,x);
			rau(p<<1|1,m+1,r,lt,rt,x);
			pushup(p);
		}
		void rs0(int p,int l,int r,int lt,int rt) 
		{
			if(rt<l||r<lt) return;
			if(lt<=l&&r<=rt) 
			{
				as0(p);
				afl(p);
				return;
			}
			pushdown(p);
			int m=(l+r)>>1;
			rs0(p<<1,l,m,lt,rt);
			rs0(p<<1|1,m+1,r,lt,rt);
			pushup(p);
		}
		int qmax(int p,int l,int r,int lt,int rt) 
		{
			if(rt<l||r<lt) return INF;
			if(lt<=l&&r<=rt) return max(st[p].mxup,st[p].mxdn);
			pushdown(p);
			int m=(l+r)>>1;
			return max(qmax(p<<1,l,m,lt,rt),qmax(p<<1|1,m+1,r,lt,rt));
		}
	};

}
using namespace DS;
namespace qaaxaap
{
	void work()
	{
		int n, q;
		cin>>n>>q;
		SegTree seg(n);
		while(q--) 
		{
			int t;
			cin>>t;
			if(t==1) 
			{
				int lt,rt;
				int x;
				cin>>lt>>rt>>x;
				seg.rau(1,1,n,lt,rt,x);
			} 
			else if(t==2) 
			{
				int lt,rt;
				cin>>lt>>rt;
				seg.rs0(1,1,n,lt,rt);
			} 
			else 
			{
				int lt,rt;
				cin>>lt>>rt;
				int ans=seg.qmax(1,1,n,lt,rt);
				if(ans<0) ans=0;
				cout<<ans<<endl;
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr),cout.tie(nullptr);
	return qaaxaap::work(),0;
}

