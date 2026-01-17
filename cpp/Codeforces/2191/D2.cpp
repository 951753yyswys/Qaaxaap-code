#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	const int mod=998244353;
	void work0()//WA
	{
		int t;
		cin>>t;
		while(t--)
		{
			int n;
			cin>>n;
			string s;
			cin>>s;
			vector<int> suf(n);
			suf[n-1]=0;
			for(int i=n-2;i>=0;i--) suf[i]=suf[i+1]+(s[i]=='(');
			int ans=0;
			for(int l=0;l<n;l++) for(int r=l+3;r<n;r+=2)
			{
				bool chk=1;
				stack<int> st;
				for(int i=l;i<=r;i++) 
				{
					if(s[i]=='(') st.push(i);
					else 
					{
						if(st.empty()) 
						{
							chk=0;
							break;
						}
						st.pop();
					}
				}
				if(!st.empty()||chk==0) continue;
				bool flag=0;
				int ed=0;
				if(r<n-1) ed=suf[r+1];
				for(int i=l;i<=r-2;i++) if(s[i]==')'&&s[i+1]=='('&&suf[i+2]-ed>0) flag=1;
				if(flag) ans=(ans+r-l+1)%mod;
			}
			cout<<ans<<endl;
		}
	}
	void work()
	{
		int t;
		cin>>t;
		while(t--)
		{	
			int n;
			string s;
			cin>>n>>s;
			vector<vector<vector<pair<int,int>>>> dp(n+1,vector<vector<pair<int,int>>>(3,vector<pair<int,int>>(3,{0,0})));
			dp[0][0][0].first=1;
			for(char tmp:s) 
			{
				auto ndp=dp; 
				for(int i=0;i<=n;i++) for(int j=0;j<3;j++) for(int k=0;k<3;k++) 
				{
					auto [cnt,sumLen]=dp[i][j][k];
					if(cnt==0) continue;
					if(tmp=='(') 
					{
						int nb=i+1;
						if(nb>n) continue;
						int nk=1;
						int nj=j;
						if(j==0&&k==2) nj=1; 
						else if(j==1) nj=2;  
						auto &to=ndp[nb][nj][nk];
						to.first=(to.first+cnt)%mod;
						to.second=(to.second+sumLen+cnt)%mod;
					} 
					else 
					{
						if(i==0) continue; 
						int nb=i-1;
						int nk=2;
						int nj=j;
						auto &to=ndp[nb][nj][nk];
						to.first=(to.first+cnt)%mod;
						to.second=(to.second+sumLen+cnt)%mod;
					}
				}
				dp=ndp;
			}
			int cntg=0,smg=0;
			for(int k:{1,2}) 
			{
				cntg=(cntg+dp[0][2][k].first) % mod;
				smg=(smg+dp[0][2][k].second) % mod;
			}
			int ans=(smg-2LL*cntg+mod*2) % mod;
			if(ans<0) ans+=mod;
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

