//当时没场切，悲
//不过输入格式和样例矛盾着实有点坑
//bro 加错东西了笑死
#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	const int mod=998244353;
	struct edge
	{
		int u,v,w;
	};
	bool cmp(edge a,edge b)
	{
		if(a.w!=b.w) return a.w>b.w;
		if(a.u!=b.u) return a.u<b.u;
		return a.v<b.v;
	}
	void work()
	{
		int t;
		cin>>t;
		while(t--)
		{
			int n,m;
			cin>>n>>m;
			vector<int> a(n);
			vector<edge> e(m);
			for(auto &tmp:a) cin>>tmp;
			for(auto &tmp:e)
			{
				int u,v,w;
				cin>>u>>v;
				u--,v--;
				tmp={u,v,a[u]+a[v]};
			}
			sort(e.begin(),e.end(),cmp);
			vector<map<int,int>> dp(n);
			int ans=0;
			for(auto tmp:e)
			{
				dp[tmp.u][a[tmp.v]]+=1+dp[tmp.v][a[tmp.v]+a[tmp.u]];
				dp[tmp.u][a[tmp.v]]%=mod;
				ans+=1+dp[tmp.v][a[tmp.v]+a[tmp.u]];
				ans%=mod;
			}
			cout<<ans<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}
