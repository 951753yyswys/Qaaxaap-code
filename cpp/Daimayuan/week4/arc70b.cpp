#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	void work()
	{
		int n,k;
		cin>>n>>k;
		vector<int> a(n);
		for(auto &tmp:a) cin>>tmp;
		sort(a.rbegin(),a.rend());
		bitset<5050> dp,can;
		dp[0]=1;
		for(int i=max(0ll,k-a[0]);i<k;i++) can[i]=1;
		int ans=0,lst=-1;
		for(auto tmp:a)
		{
			for(int i=max(0ll,k-a[max(0ll,lst)]);i<=k-tmp-1;i++) can[i]=0;lst++;
			if((dp&can).count()) ans=lst+1;
			dp|=dp<<tmp;
		}
		cout<<n-ans;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

