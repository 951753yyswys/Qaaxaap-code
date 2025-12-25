#include<bits/stdc++.h>
#define int long long
#define lt ro<<1
#define rt ro<<1|1
using namespace std;
namespace DS
{
	class seg
	{
	public:
		struct node
		{
			int l,r;
			int num,tag,sum,mx;
		};
		vector<node> t;
		seg(int n){t.resize(n*5+10);build(1,1,n);}
		void pushdown(int ro)
		{		
			if(t[ro].tag==-1) return;
			t[lt].num=t[ro].tag;
			t[lt].tag=t[ro].tag;
			t[lt].mx=t[ro].tag;
			t[lt].sum=t[lt].num*(t[lt].r-t[lt].l+1);
			t[rt].num=t[ro].tag;
			t[rt].tag=t[ro].tag;
			t[rt].mx=t[ro].tag;
			t[rt].sum=t[rt].num*(t[rt].r-t[rt].l+1);
			t[ro].tag=-1;
		}
		void pushup(int ro)
		{
			t[ro].sum=t[lt].sum+t[rt].sum;
			t[ro].mx=max(t[lt].mx,t[rt].mx);
		}
		void build(int ro,int l,int r)
		{
			t[ro].l=l;
			t[ro].r=r;
			t[ro].tag=-1;
			if(l==r) 
			{
				t[ro].num=t[ro].sum=INT_MAX;
				return;
			}
			int mid=l+r>>1;
			build(ro<<1,l,mid);
			build(ro<<1|1,mid+1,r);
			pushup(ro);
		}
		void update(int ro,int l,int r,int val)
		{
			if(t[ro].l>=l&&t[ro].r<=r) 
			{
				t[ro].num=val;
				t[ro].sum=val*(t[ro].r-t[ro].l+1);
				t[ro].mx=val;
				t[ro].tag=val;
				return;
			}
			pushdown(ro);
			if(t[lt].r>=l) update(ro<<1,l,r,val);
			if(t[rt].l<=r) update(ro<<1|1,l,r,val);
			pushup(ro);
		}
		int qsum(){return t[1].sum;}
		int qmax(){return t[1].mx;}
		~seg()=default;
	};
}
using namespace DS;
namespace Qaaxaap
{
	struct vs{int c,l,r;void prt(){cout<<c<<' '<<l<<' '<<r<<endl;}};
	bool cmp(vs x,vs y)
	{
		if(x.c!=y.c) return x.c>y.c;
		if(x.l!=y.l) return x.l>y.l;
		return x.r>y.r;
	}
	void work()
	{
		int t;
		cin>>t;
		while(t--)
		{
			int n;
			cin>>n;
			vector<int> a(n),c(n),l(n),r(n,n-1);
			for(auto &tmp:a) cin>>tmp;
			for(auto &tmp:c) cin>>tmp;
			stack<pair<int,int>> st;
			for(int i=0;i<n;i++)
			{
				while(!st.empty()&&st.top().second<=a[i]) st.pop();
				if(!st.empty()) l[i]=st.top().first+1;
				st.push({i,a[i]});
			}
			while(!st.empty()) st.pop();
			for(int i=n-1;i>=0;i--)
			{
				while(!st.empty()&&st.top().second<=a[i]) st.pop();
				if(!st.empty()) r[i]=st.top().first-1;
				st.push({i,a[i]});
			}
			//for(int i=0;i<n;i++) cout<<l[i]<<' '<<r[i]<<endl;
			vector<vs> fs(n);
			for(int i=0;i<n;i++) fs[i].c=c[i],fs[i].l=l[i],fs[i].r=r[i];
			sort(fs.begin(),fs.end(),cmp);
			seg tr(n);
			for(auto tmp:fs) tr.update(1,tmp.l+1,tmp.r+1,tmp.c);		
			cout<<tr.qsum()-tr.qmax()<<' ';
			for(int ii=1;ii<=n;ii++)
			{
				int p;
				cin>>p;p--;
				tr.update(1,l[p]+1,r[p]+1,0);
				cout<<tr.qsum()-tr.qmax()<<' ';
			}
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

