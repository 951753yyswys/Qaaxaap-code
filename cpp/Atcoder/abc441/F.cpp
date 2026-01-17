#include<bits/stdc++.h>
using namespace std;
namespace Qaaxaap
{
	using ll=long long;
	void work()
	{
		int n,m;
		cin>>n>>m;
		vector<int> p(n+1);
		vector<ll> v(n+1);
		for(int i=1;i<=n;++i) cin>>p[i]>>v[i];
		int w=m+1;
		vector<ll> prf(1ll*(n+1)*w,0);
		for(int i=1;i<=n;++i) 
		{
			int pt=p[i];
			ll vt=v[i];
			ll* pre=&prf[1LL*(i-1)*w];
			ll* cur=&prf[1LL*i*w];
			int wt=0;
			for(;wt<pt;++wt) cur[wt]=pre[wt];
			for(;wt<=m;++wt) 
			{
				ll a=pre[wt];
				ll b=pre[wt-pt]+vt;
				cur[wt]=max(a,b);
			}
		}
		ll opt=prf[1LL*n*w+m];
		vector<ll> suf(w,0); 
		string ans(n,'B');
		for(int i=n;i>=1;--i) 
		{
			int pt=p[i];
			ll vt=v[i];
			ll* pre=&prf[1LL*(i-1)*w];
			bool ex=0,in=0;
			int a=m;
			int b=m-pt;
			for(int wt=0;wt<=m;++wt,--a,--b) 
			{
				ll l=pre[wt];
				if(!ex) 
				{
					ll cd=l+suf[a];
					if(cd==opt) ex=1;
				}
				if(!in&&wt<=m-pt) 
				{
					ll cd=l+vt+suf[b];
					if(cd==opt) in=1;
				}
				if(ex&&in) break; 
			}
			if(in&&!ex) ans[i-1]='A';
			else if(in&&ex) ans[i-1]='B';
			else ans[i-1]='C';
			for(int wt=m;wt>=pt;--wt) 
			{
				ll cd=suf[wt-pt]+vt;
				if(cd>suf[wt]) suf[wt]=cd;
			}
		}
		cout<<ans;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

