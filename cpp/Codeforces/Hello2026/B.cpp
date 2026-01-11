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
			int n,k;
			cin>>n>>k;
			vector<int> a(n),cnt(n+1);
			for(auto &tmp:a) cin>>tmp,cnt[tmp]++;
			int ans=0;
			for(int i=0;i<=n;i++)
			{
				if(cnt[i]) ans=i+1;
				else break;
			}
			cout<<min(ans,k-1)<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

