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
			vector<int> vis(1<<n);
			int lst=(1ll<<n);
			for(int i=n;i>0;i--) 
			{
				int now=(1ll<<i)-1;
				for(int j=0;(j<<i+1)+now<(1ll<<n);j++) cout<<now+(j<<i+1)<<' ',vis[now+(j<<i+1)]=1;
				lst=now;
			}
			cout<<0<<' ';
			for(int i=1;i<(1ll<<n);i++) if(!vis[i]) cout<<i<<' ';
			cout<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

