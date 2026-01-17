#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	void work()
	{
		int n,k,x;
		cin>>n>>k>>x;
		vector<int> a(n);
		for(auto &tmp:a) cin>>tmp;
		sort(a.begin(),a.end());
		int sum=0,fst=LLONG_MAX;
		for(int i=0;i<k;i++) 
		{
			sum+=a[i];
		}
		if(sum<x)
		{
			cout<<-1;
			return;
		}
		sum=0;
		for(int i=k-1;i>=0;i--)
		{
			sum+=a[i];
			if(sum>=x) fst=min(fst,k-i);
		}
		cout<<n-(k-fst);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

