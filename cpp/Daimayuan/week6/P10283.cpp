#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	const int N=5e6;
	int cnt,dp[N],ans;
	struct node{int ls,rs,num,ed;} t[N];
	void build(string s)
	{
		int now=0;
		for(char tmp:s)
		{
			if(tmp=='1')
			{
				if(!t[now].rs) t[now].rs=++cnt;
				now=t[now].rs;
			}
			else 
			{
				if(!t[now].ls) t[now].ls=++cnt;
				now=t[now].ls;
			}
		}
		t[now].ed++;
	}
	void pushup(int ro)
	{
		if(t[ro].ls+t[ro].rs==0) dp[ro]=2;
		else if(t[ro].ls==0||t[ro].rs==0) dp[ro]=1;
		else dp[ro]=min(dp[t[ro].ls],dp[t[ro].rs])+1;
	}
	void pushdown(int ro)
	{
		if(t[ro].ls+t[ro].rs==0)
		{
			t[ro].ls=++cnt;
			t[ro].rs=++cnt;
			dp[cnt]=dp[cnt-1]=2;
			pushup(ro);
			return;
		}
		if(t[ro].ls==0)
		{
			t[ro].ls=++cnt;
			dp[cnt]=2;
			pushup(ro);
			return;
		}
		if(t[ro].rs==0)
		{
			t[ro].rs=++cnt;
			dp[cnt]=2;
			pushup(ro);
			return;
		}
		if(dp[t[ro].ls]<dp[t[ro].rs]) pushdown(t[ro].ls);
		else pushdown(t[ro].rs);
		pushup(ro);
	}
	void dfs(int ro)
	{
		if(t[ro].ls) dfs(t[ro].ls);
		if(t[ro].rs) dfs(t[ro].rs);
		if(t[ro].ls+t[ro].rs==0) dp[ro]=2,t[ro].ed--;
		else if(t[ro].ls==0||t[ro].rs==0) dp[ro]=1;
		else dp[ro]=min(dp[t[ro].ls],dp[t[ro].rs])+1;
		while(t[ro].ed--)
		{
			ans+=dp[ro];
			pushdown(ro);
		}
	}
	void work()
	{
		memset(dp,0x3f,sizeof dp);
		int n;
		cin>>n;
		while(n--)
		{
			string s;
			cin>>s;
			build(s);
		}
		dfs(0);
		cout<<ans;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

