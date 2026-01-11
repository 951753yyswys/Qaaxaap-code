#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	void work()
	{
		int n,q;
		cin>>n>>q;
		vector<int> a(n),gap(n),prf(n);
		for(auto &tmp:a) cin>>tmp;
		sort(a.begin(),a.end());
		for(int i=0;i<n;i++)
		{
			int st=1;
			if(i>0) st=a[i-1]+1;
			int ed=a[i]-1;
			int len=max(ed-st+1,0ll);
			gap[i]=st;
			if(i==0) prf[i]=len;
			else prf[i]=len+prf[i-1];
		}
		int mis=prf[n-1];
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			int idx=lower_bound(a.begin(),a.end(),x)-a.begin();
			int r=x-1-idx;
			int k=r+y;
			int ans;
			if(k>mis) ans=a.back()+(k-mis);
			else
			{
				int pos=lower_bound(prf.begin(),prf.end(),k)-prf.begin();
				int prv=0;
				if(pos>0) prv=prf[pos-1];
				ans=gap[pos]+k-prv-1;
			}
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
	
