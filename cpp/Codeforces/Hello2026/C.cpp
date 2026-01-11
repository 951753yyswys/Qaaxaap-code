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
			int n,m,k;
			cin>>n>>m>>k;
			int ans=0;
			for(int i=0;i<k;i++)
			{
				int r=min({i,n-k,m-2*i+1});
				ans=max(ans,r+i);
			}
			for(int i=0;i<=n-k;i++)
			{
				int l=min({i,k-1,m+1-2*i});
				ans=max(ans,l+i);
			}
			cout<<ans+1<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

