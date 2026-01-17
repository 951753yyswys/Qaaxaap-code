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
			bool flag0=1,flag1=1;
			for(int i=1;i<=n;i++)
			{
				int tmp;
				cin>>tmp;
				if(tmp%2!=i%2) flag0=0;
				if(tmp%2==i%2) flag1=0;
			}
			if(flag1||flag0) cout<<"Yes"<<endl;
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

