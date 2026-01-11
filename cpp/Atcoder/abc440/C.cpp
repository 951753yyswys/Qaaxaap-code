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
			int n,w;
			cin>>n>>w;
			w<<=1;
			vector<int> c(n),sm(2*w+1);
			for(int i=0;i<n;i++)
			{
				cin>>c[i];
				sm[i%w+1]+=c[i]; 
				sm[i%w+1+w]+=c[i];
			}
			for(int i=2;i<=w*2;i++) sm[i]+=sm[i-1];
			int ans=LLONG_MAX;
			for(int i=1;i<=w;i++) ans=min(ans,sm[i+w/2-1]-sm[i-1]);
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

