#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	const int N=5e4+5,mod=998244353;
	void work()
	{
		int t;
		cin>>t;
		while(t--)
		{
			int n,m,cnt=0;
			cin>>n>>m;
			vector<vector<int>> a(n);
			vector<vector<bitset<N>>> mp(m,vector<bitset<N>>(m));
			for(auto &tmp:a) 
			{
				for(int i=1;i<=m;i++) 
				{
					int v;
					cin>>v;
					tmp.push_back(v-1);
					mp[v-1][i-1][cnt]=1;
				}
				cnt++;
			}
			for(int i=0;i<n;i++)
			{
				int ans=0,lst=1;
				bitset<N> chk=mp[0][a[i][0]];
				if(chk!=0) 
				{
					ans=1;
					while(lst<m) 
					{
						chk&=mp[lst][a[i][lst]],lst++;
						if(chk!=0) ans++;
						else break;
					}
				}
				cout<<ans<<' ';
			}
			cout<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return Qaaxaap::work(),0;
}

