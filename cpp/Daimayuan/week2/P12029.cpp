#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	const int N=5e5+5,mod=998244353;
	void work()
	{
		int n,q;
		cin>>n>>q;
		vector<int> a(n+1),tic(n+1);
		for(int i=1;i<=n;i++) cin>>a[i],tic[a[i]]++,buc[a[i]].insert(i);
		vector<set<int>> buc(n+1);
		set<int> alm;
		vector<int> prf(n+1);
		for(int i=1;i<=n;i++) if(tic[i]) alm.insert(tic[i]);
		{
			int mx=0;
			auto i=prev(alm.end());
			while(1)
			{
				int u=*i;
				prf[tic[u]]=max(prf[tic[u]]],ui);
				mx=max(mx,prf[tic[u]]);
				prf[tic[u]]=mx;
				if(i==alm.begin()) break;
				i=prev(alm.begin());
			}
		}
		{
			auto rit=prev(alm.end());
			auto it=alm.begin();
			while(rit!=it)
			{
				
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return Qaaxaap::work(),0;
}

