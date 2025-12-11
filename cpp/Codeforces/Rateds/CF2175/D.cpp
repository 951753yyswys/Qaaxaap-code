#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	const int N=5e5+5,mod=998244353;
	void work()
	{
		int t;
		cin>>t;
		while(t--)
		{
			int n,k;
			cin>>n>>k;
			vector<int> a(n);
			for(auto &tmp:a) cin>>tmp;
			vector<int> cnt(k+1);
            int lmx=-1;
            for(auto tmp:a) lmx=max(lmx,tmp),cnt[lmx]++;
			for(int i=k;i>=1;i--) cnt[i-1]+=cnt[i];
			vector<vector<int>> dp(k+1,vector<int>(k+1));
			for(int i=1;i<=k;i++)
			{
				for(int j=k;j>=i;j--) 
				{
					for(int l=0;l<i;l++)
						dp[j][i]=max(dp[j-i][l]+cnt[i]*i-cnt[i]*l,dp[j][i]);
				}
			}
			int mx=0;
			for(int i=0;i<=k;i++) for(int j=0;j<=k;j++) mx=max(mx,dp[i][j]);
			cout<<mx<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return Qaaxaap::work(),0;
}

