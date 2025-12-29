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
			int ans=0;
			int n;
			cin>>n;
			vector<int> a(n),b(n),c(n);
			for(auto &tmp:a) cin>>tmp;
			for(auto &tmp:b) cin>>tmp;
			for(auto &tmp:c) cin>>tmp;
			int sb=0;
			for(int i=0;i<n;i++)
			{
				bool flag=1;	
				for(int j=0;j<n;j++) if(b[j]>=c[(i+j)%n])	
				{
					flag=0;
					break;
				}	
				sb+=flag;
			}
			int sa=0;
			for(int i=0;i<n;i++)
			{
				bool flag=1;
				for(int j=0;j<n;j++) if(a[j]>=b[(i+j)%n])
				{
					flag=0;
					break;
				}
				sa+=flag;
			}
			//cout<<' '<<sa<<' '<<sb<<endl;
			cout<<n*sa*sb<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

