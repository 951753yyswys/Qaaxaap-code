#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	void work()
	{
		int t;
		cin>>t;
		while(t--)
		{
			int n;
			cin>>n;
			vector<int> a(n),sum(n);
			int ans=0;
			bool flag=0;
			map<int,int> cnt;
			for(auto &tmp:a) cin>>tmp;
			sum[0]=a[0];
			for(int i=1;i<n;i++) sum[i]=a[i]+sum[i-1];
			for(int i=0;i<n;i++)	
			{
				if(a[i]==0)
				{
					if(flag==0) flag=1,ans+=cnt[0],cnt.clear();
					else 
					{
						int mx=0;
						for(auto [id,cnp]:cnt) mx=max(cnp,mx);
						ans+=mx;
						cnt.clear();
					}
				}
				cnt[sum[i]]++;
			}
			int mx=0;
			for(auto [id,cnp]:cnt) mx=max(mx,cnp);
			ans+=flag*mx;
			ans+=(flag^1)*cnt[0];
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

