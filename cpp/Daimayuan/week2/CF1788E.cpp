//线段树优化 DP 模板题
#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace DS
{
	template<typename T> 
	class segment_tree
	{
	private:
		struct treenode
		{
			int l,r;
			T num;
		};
		vector<treenode> t;
		void build(int ro,int l,int r,T val)
		{
			t[ro].l=l;
			t[ro].r=r;
			t[ro].num=val;
			if(l==r) return;
			int mid=l+r>>1;
			build(ro<<1,l,mid,val);
			build(ro<<1|1,mid+1,r,val);
		}
		void update(int ro,int pos,T val)
		{
			if(t[ro].l==t[ro].r) 
			{
				t[ro].num=max(t[ro].num,val);
				return;
			}
			if(pos<=t[ro<<1].r) update(ro<<1,pos,val);
			else update(ro<<1|1,pos,val);
			t[ro].num=max(t[ro<<1].num,t[ro<<1|1].num);
		}
		T query(int ro,int l,int r,T val)
		{
			if(t[ro].l>=l&&t[ro].r<=r) return t[ro].num;
			T ret=val;
			if(t[ro<<1].r>=l) ret=query(ro<<1,l,r,val);
			if(t[ro<<1|1].l<=r) ret=max(ret,query(ro<<1|1,l,r,val));
			return ret;
		}
	public:
		int n;
		T SIMVAL;
		segment_tree(int x,T val) 
		{
			t.resize(x*5);
			n=x;
			SIMVAL=val;
			build(1,1,x,val);
		}
		void update(int pos,T val){update(1,pos,val);}
		T query(int l,int r){return query(1,l,r,SIMVAL);}
		void print()
		{
			for(int i=1;i<=n;i++) cout<<query(i,i)<<endl;
		}
	};
	template<typename T>
	class to_unique
	{
	private:
		vector<T> old;
		vector<int> fold;
		vector<pair<int,int>> nw;
	public:
		to_unique(vector<T> &x)
		{
			old=x;
			int n=x.size();
			fold.resize(n);
			int cnt=0;
			set<int> temp;
			for(auto tmp:old) temp.insert(tmp);
			for(auto tmp:temp) nw.push_back({tmp,++cnt});
			for(int i=0;i<n;i++) fold[i]=(*lower_bound(nw.begin(),nw.end(),make_pair(old[i],0ll))).second;
		}
		int f(int x){return fold[x];}
	};
}
using namespace DS;
namespace Qaaxaap
{
	const int N=5e5+5,mod=998244353;
	void work()
	{
		int n;
		cin>>n;
		vector<int> a(n),prefix(n),dp(n);
		for(auto &tmp:a) cin>>tmp;
		prefix[0]=a[0];
		for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+a[i];
		prefix.push_back(0);
		segment_tree<int> tree(n+1,-0x7fffffffffffff);
		to_unique<int> lprefix(prefix);
		tree.update(lprefix.f(n),1);
		//tree.print();
		//for(auto tmp:prefix) cout<<tmp<< ' ';
		//cout<<endl;
		//for(int i=0;i<=n;i++) cout<<lprefix.f(i)<<' ';
		//cout<<endl;
		int mx=0;
		for(int i=0;i<n;i++)
		{
			dp[i]=tree.query(1,lprefix.f(i))+i;
			if(a[i]>=0) dp[i]=max(dp[i],mx+1ll);
			else dp[i]=max(dp[i],mx);
			mx=max(mx,dp[i]);
			tree.update(lprefix.f(i),dp[i]-i);
		}
		//for(auto tmp:dp) cout<<tmp<<' ';
		//cout<<endl;
		cout<<max((*max_element(dp.begin(),dp.end())),0ll)<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return Qaaxaap::work(),0;
}

