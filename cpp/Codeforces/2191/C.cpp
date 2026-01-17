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
			int n,cnt1=0,cnt0=0;
			cin>>n;
			string s,t;
			cin>>s;
			for(char tmp:s)
			{
				if(tmp=='1') cnt1++;
				else cnt0++;
			}
			for(int i=1;i<=cnt0;i++) t+='0';
			for(int i=1;i<=cnt1;i++) t+='1';
			if(s==t) 
			{
				cout<<"Bob"<<endl;
				continue;
			}
			vector<int> ans;
			for(int i=0;i<n;i++) if(s[i]!=t[i]) ans.push_back(i+1);
			cout<<"Alice"<<endl<<ans.size()<<endl;
			for(auto tmp:ans) cout<<tmp<<' ';
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

