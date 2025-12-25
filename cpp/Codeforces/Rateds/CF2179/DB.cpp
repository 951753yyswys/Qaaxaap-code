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
			int n,mx=0;
			cin>>n;
			vector<int> a;
			for(int i=0;i<(1<<n)-1;i++) a.push_back(i);
			for(auto tmp:a) cout<<tmp<<' ';
			cout<<endl;
			while(1)
			{
				int ans=0,ad=a[0];
				for(auto tmp:a)
				{
					ad&=tmp;
					ans+=__builtin_popcountll(ad);
				}
				if(ans>mx) 
				{
					mx=ans;
					for(auto tmp:a) cout<<tmp<<' ';
					cout<<endl;
				}
				if(!next_permutation(a.begin(),a.end())) break;
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

