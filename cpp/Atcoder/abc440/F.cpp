#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace DS
{
	class fenw
	{
	public:
		vector<int> t;
		int siz;
		fenw(int n){init(n);}
		void init(int n)
		{
			siz=n;
			t.assign(n+1,0);
		}
		int lowb(int x){return x&-x;}
		void add(int val,int idx)
		{
			while(idx<=siz)
			{
				t[idx]+=val;
				idx+=lowb(idx);
			}
		}
		int ask(int idx)
		{
			int ret=0;
			while(idx>0)
			{
				ret+=t[idx];
				idx-=lowb(idx);
			}
			return ret;
		}
		int kth(int k)
		{
			int idx=0;
			int bm=1;
			while((bm<<1)<=siz) bm<<=1;
			for(int st=bm;st>0;st>>=1)
			{
				int nxt=idx+st;
				if(nxt<=siz&&t[nxt]<k)
				{
					idx=nxt;
					k-=t[nxt];
				}
			}
			return idx+1;
		}
	};
}
using namespace DS;
namespace Qaaxaap
{
	void work()
	{
		int n,q;
		cin>>n>>q;
		vector<int> a(n+1),b(n+1),w(q+1),x(q+1),y(q+1),auv;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i];
			auv.push_back(a[i]);
		}
		for(int k=1;k<=q;k++)
		{
			cin>>w[k]>>x[k]>>y[k];
			auv.push_back(x[k]);
		}
		sort(auv.begin(),auv.end());
		auv.erase(unique(auv.begin(),auv.end()),auv.end());
		int M=auv.size();
		auto gp=[&](int val)->int{return lower_bound(auv.begin(),auv.end(),val)-auv.begin()+1;};
		auto gv=[&](int pos)->int{return auv[pos-1];};
		fenw cnta(M),suma(M),cntb(M);
		int tota=0;
		int c2=0;
		for(int i=1;i<=n;i++)
		{
			int p=gp(a[i]);
			cnta.add(1,p);
			suma.add(a[i],p);
			tota+=a[i];
			if(b[i]==2) c2++;
			else cntb.add(1,p);
		}
		auto sua=[&](int t)->int
        {
			if(t<=0) return 0;
			if(t>=n) return tota;
			int idx=cnta.kth(t);
			int cnbf=cnta.ask(idx-1);
			int subf=suma.ask(idx-1);
			int need=t-cnbf;
			int v=gv(idx);
			return subf+need*v;
		};
		auto tp=[&](int k)->int
        {
			if(k<=0) return 0;
			if(k>=n) return tota;
			return tota-sua(n-k);
		};
		auto kt=[&](int k)->int
        {
			int rk=n-k+1;
			int idx=cnta.kth(rk);
			return gv(idx);
		};
		auto mp=[&]()->int
        {
			int c1=n-c2;
			int idx=cntb.kth(c1);
			return gv(idx);
		};
		for(int qi=1;qi<=q;qi++)
		{
			int i=w[qi];
			{
				int p=gp(a[i]);
				cnta.add(-1,p);
				suma.add(-a[i],p);
				tota-=a[i];
				if(b[i]==2) c2--;
				else cntb.add(-1,p);
			}
			a[i]=x[qi];
			b[i]=y[qi];
			{
				int p=gp(a[i]);
				cnta.add(1,p);
				suma.add(a[i],p);
				tota+=a[i];
				if(b[i]==2) c2++;
				else cntb.add(1,p);
			}
			int c1=n-c2;
			int best=LLONG_MIN;
			if(c2>0)
			{
				int bonus=tp(c2-1);
				best=max(best,tota+bonus);
			}
			if(c1>0)
			{
				if(c2==0)best=max(best,tota);
				else
				{
					int T=tp(c2);
					int v=kt(c2); 
					int mx1=mp();           
					int bonus=(mx1>=v)?T:(T-v+mx1);
					best=max(best,tota+bonus);
				}
			}
			cout<<best<<endl;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}
