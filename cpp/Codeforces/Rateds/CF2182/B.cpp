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
			int a,b;
			cin>>a>>b;
			int ans=0,lst=1,ma=a,mb=b;
			for(int i=1;i<=2;i++)
			{
				lst=1;
				int lans=0;
				bool flag=0;
				while(1)
				{
					flag^=1;
					if(flag)
					{
						if(ma-lst>=0) ma-=lst,lans++;
						else break;
					}
					else 
					{
						if(mb-lst>=0) mb-=lst,lans++;
						else break;
					}
					lst<<=1;
				}
				ma=b;
				mb=a;
				ans=max(lans,ans);
			}
			cout<<ans<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}
