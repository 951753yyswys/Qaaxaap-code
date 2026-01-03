#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	int vis[10000001];
	void work()
	{
		int n,ans=0;
		cin>>n;
		for(int i=1;i*i<=n;i++) for(int j=i+1;j*j<=n;j++) if(i*i+j*j<=n) vis[i*i+j*j]++;
		for(int i=1;i<=n;i++) if(vis[i]==1) ans++;
		cout<<ans<<endl;
		for(int i=1;i<=n;i++) if(vis[i]==1) cout<<i<<' ';
	}	
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

