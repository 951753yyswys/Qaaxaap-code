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
			int n,m;
			cin>>n>>m;
			string s;
			cin>>s;
			set<pair<int,int>> ans;
			s='+'+s;
			int flag=0;
			while(m--)
            {
				int l,r;
				cin>>l>>r;
				cout<<l<<' '<<r<<endl;
				if(l>=r) flag=1;
				if(l>=r) continue;
				ans.insert({l,r});
			}
			cout<<ans.size()+flag<<endl;
		}	
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

