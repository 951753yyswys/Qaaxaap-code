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
			string s;
			cin>>s;
			int cnt=0;
			for(char tmp:s) if(tmp=='Y') cnt++;
			if(cnt>1) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

