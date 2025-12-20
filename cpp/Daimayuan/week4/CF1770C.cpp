#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	void work()
	{
		vector<int> npr(1010),pri;
		npr[1]=1;
		for(int i=2;i<=1000;i++) 
		{
			if(npr[i]==0) pri.push_back(i);
			for(auto prj:pri)
			{
				if(prj*i>1000) break;
				npr[prj*i]=1;
				if(i%prj==0) break;
			}
		}
		int t;
		cin>>t;
		while(t--)
		{
			int n;
			cin>>n;
			vector<int> a(n);
			for(auto &tmp:a) cin>>tmp;
			sort(a.begin(),a.end());
			bool flag=1;
			for(int i=1;i<n;i++) 
			{
				if(a[i]==a[i-1]) 
				{
					flag=0;
					break;
				}
			}
			for(auto prj:pri)
			{
				if(prj>n/2) break;
				if(flag==0) break;
				vector<int> cnt(prj);
				for(auto tmp:a) cnt[tmp%prj]++;
				if(*min_element(cnt.begin(),cnt.end())>1) flag=0;
			}
			if(flag) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

