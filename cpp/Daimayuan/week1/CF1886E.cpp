#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	const int N=5e5+5,mod=998244353;
	int yk[22][200002],a[202020],inv[202020],b[22],dp[1<<21],lst[1<<21],lsp[1<<21];
	pair<int,int> ya[202020];
	void work()
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>ya[i].first,ya[i].second=i;
		for(int i=1;i<=m;i++) cin>>b[i];
		sort(ya+1,ya+n+1);
		for(int i=1;i<=n;i++) a[i]=ya[i].first,inv[i]=ya[i].second;
		memset(yk,-1,sizeof(yk));
		memset(dp,-1,sizeof(dp));
//		for(int i=1;i<=n;i++) cout<<a[i]<<' ';
//		cout<<endl;
		for(int cc=1;cc<=m;cc++)
		{
			int l=n;
			for(int r=n;r>=1;r--)
			{
				l=min(l,r);
				while(l>1&&a[l]<(int)ceil(b[cc]*1.0/(r-l+1))) l--;
//				cout<<"(l,r)"<<l<<' '<<r<<endl;
				if(a[l]>=(int)ceil(b[cc]*1.0/(r-l+1))) yk[cc][r]=l;
			}
//			for(int i=1;i<=n;i++) cout<<yk[cc][i]<<' ';
//			cout<<endl;
		}
		dp[0]=n;
		for(int i=0;i<(1<<m);i++)
		{
			if(dp[i]<=0) continue;
			for(int j=0;j<m;j++)
			{
				int pos=1<<j;
				if((pos|i)==i) continue;
				if(dp[pos|i]<yk[j+1][dp[i]]-1) lst[pos|i]=i,lsp[pos|i]=j,dp[pos|i]=yk[j+1][dp[i]]-1;
			}
		}
		for(int i=0;i<(1<<m);i++)
		{
			cout<<"mask:"<<i<<' ';
			cout<<dp[i]<<endl;
		}
		if(dp[(1<<m)-1]<0) 
		{
			cout<<"NO";
			return;
		}
		cout<<"YES"<<endl;
		int rt=n,now=(1<<m)-1;
		vector<int> opt;
		while(lst[now]!=now) opt.push_back(lsp[now]),now=lst[now];
		vector<vector<int>> ans(m);
		for(int i=opt.size()-1;i>=0;i--)
		{
			int lt=yk[opt[i]+1][rt];
//			cout<<lt<<' '<<rt<<endl;
			for(int j=lt;j<=rt;j++) ans[opt[i]].push_back(inv[j]);
			rt=lt-1;
		}
		for(auto tmp:ans)
		{
			cout<<tmp.size()<<' ';
			for(auto tmp1:tmp) cout<<tmp1<<' ';
			cout<<endl;
		}
	}
}
signed main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0),cout.tie(0);
	return Qaaxaap::work(),0;
}

