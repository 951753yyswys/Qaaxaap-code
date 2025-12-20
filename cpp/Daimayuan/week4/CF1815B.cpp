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
			int n,rubs;
			cin>>n;
			vector<int> ans1(n+1),ans2(n+1),inv(n+1);
			int l=1,r=n;
			cout<<"+ "<<n+1<<endl;
			cin>>rubs;
			cout<<"+ "<<n+2<<endl;
			cin>>rubs;
			for(int i=1;i<=n;i++)
			{
				if(i&1) inv[i]=l++;
				else inv[i]=r--;
			}
			int mx=0,opt;
			for(int i=2;i<=n;i++)
			{
				cout<<"? "<<1<<' '<<i<<endl;
				int tmp;
				cin>>tmp;
				assert(tmp!=-1);
				if(tmp>mx) opt=i,mx=tmp;
			}
			for(int i=1;i<=n;i++)
			{
				if(i==opt)
				{
					ans1[i]=inv[1];
					ans2[i]=inv[n];
					continue;
				}
				cout<<"? "<<opt<<' '<<i<<endl;
				int tmp;
				cin>>tmp;
				assert(tmp!=-1);
				ans1[i]=inv[tmp+1];
				ans2[i]=inv[n-tmp];
			}
			cout<<"!";
			for(int i=1;i<=n;i++) cout<<' '<<ans1[i];
			for(int i=1;i<=n;i++) cout<<' '<<ans2[i];
			cout<<endl;
			int res;
			cin>>res;
			assert(res==1);
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

