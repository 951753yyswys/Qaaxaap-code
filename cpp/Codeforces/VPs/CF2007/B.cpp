#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace DS
{
	class seg
	{
	public:
		struct node{int l,r;int tag,mx;};vector<node> t;seg(int n){t.resize((n+1)*5);}void pushup(int ro){t[ro].mx=max(t[ro<<1].mx,t[ro<<1|1].mx);}bool init(int ro,int l,int r){return t[ro].l>=l&&t[ro].r<=r;}
		void pushdown(int ro){t[ro<<1].tag+=t[ro].tag,t[ro<<1].mx+=t[ro].tag,t[ro<<1|1].tag+=t[ro].tag,t[ro<<1|1].mx+=t[ro].tag;t[ro].tag=0;}
		void build(int ro,int l,int r,vector<int>&a){t[ro].l=l;t[ro].r=r;if(l==r){t[ro].mx=a[l];return;}int mid=l+r>>1;build(ro<<1,l,mid,a);build(ro<<1|1,mid+1,r,a);pushup(ro);}
		void update(int ro,int l,int r,int val){if(init(ro,l,r)){t[ro].mx+=val,t[ro].tag+=val;return;}pushdown(ro);if(t[ro<<1].r>=l)update(ro<<1,l,r,val);if(t[ro<<1|1].l<=r)update(ro<<1|1,l,r,val);pushup(ro);}
		int query(int ro,int l,int r){if(init(ro,l,r))return t[ro].mx;pushdown(ro);int mx=-1e9;if(t[ro<<1].r>=l)mx=query(ro<<1,l,r);if(t[ro<<1|1].l<=r)mx=max(mx,query(ro<<1|1,l,r));return mx;}
	};
}
using namespace DS;
namespace Qaaxaap
{
	void work()
	{
		int t;cin>>t;//while(t--){int n,m;cin>>n>>m;vector<int> a(n+1);for(int i=1;i<=n;i++)cin>>a[i];seg tr(n);tr.build(1,1,n,a);
		//while(m--){char opt;int l,r,val=0;cin>>opt>>l>>r;if(opt=='+')val=1;else val=-1;tr.update(1,l,r,val);cout<<tr.query(1,1,n)<<' ';}cout<<endl;}
		while(t--){int n,m,mx=0;cin>>n>>m;for(int i=1;i<=n;i++){int tmp;cin>>tmp;mx=max(mx,tmp);}while(m--){char opt;int l,r,val;cin>>opt>>l>>r;if(opt=='+')val=1;else val=-1;if(l<=mx&&r>=mx)mx+=val;
		cout<<mx<<' ';}cout<<endl;}
	}
}
signed main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

