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
			vector<int> cnt(n+1);
			for(int i=1;i<=n;i++)
			{
				int tmp;
				cin>>tmp;
				cnt[tmp]++;
			}
			if(cnt[0]==0) cout<<"No"<<endl;
			else 
			{
				if(cnt[0]==1) cout<<"Yes"<<endl;
				else if(cnt[1]) cout<<"Yes"<<endl;
				else cout<<"No"<<endl;
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

