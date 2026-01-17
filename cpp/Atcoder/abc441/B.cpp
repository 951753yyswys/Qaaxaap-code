#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	void work()
	{
		int n,m;
		string a,b;
		cin>>n>>m;
		cin>>a>>b;
		map<char,int> s,t;
		for(char tmp:a) s[tmp]=1;
		for(char tmp:b) t[tmp]=1;
		int q;
		cin>>q;
		while(q--)
		{
			string w;
			cin>>w;
			bool tk=1,ao=1;
			for(char tmp:w)
			{
				if(s[tmp]==0) tk=0;
				if(t[tmp]==0) ao=0;
			}
			if(tk+ao==1) 
			{
				if(tk) cout<<"Takahashi"<<endl;
				else cout<<"Aoki"<<endl;
			}
			else cout<<"Unknown"<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

