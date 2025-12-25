#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	int ab(int x)
	{
		if(x<0) x=(-1ll)*x;
		return x;
	}
	void work()
	{
		int t;
		cin>>t;
		while(t--)
		{
			int n;
			cin>>n;
			vector<int> a(n);
			for(auto &tmp:a) cin>>tmp;
			int k=-1,mx=0;
			for(int i=0;i<n;i++)
			{
				int cg=ab(a[i]-a[min(n-1,i+1)])+ab(a[i]-a[max(i-1,0ll)])-ab(a[min(n-1,i+1)]-a[max(i-1,0ll)]);
				if(cg>mx) k=i,mx=cg;
			}
			if(ab(a[0]-a[1])>mx) k=0,mx=ab(a[0]-a[1]);
			if(ab(a[n-1]-a[n-2])>mx) k=n-1;
			int ans=0;
			vector<int> b;
			for(int i=0;i<n;i++) if(i!=k) b.push_back(a[i]);
			for(int i=1;i<b.size();i++) ans+=ab(b[i]-b[i-1]);
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

