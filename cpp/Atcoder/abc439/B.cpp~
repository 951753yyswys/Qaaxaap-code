#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	int th(int x)
	{
		int ans=0;
		while(x)
		{
			int tmp=x%10;
			ans+=tmp*tmp;
			x/=10;
		}
		return ans;
	}
	void work()
	{
		int n,flag=0;
		map<int,int> vis;
		cin>>n;
		vis[n]=1;
		while(n>1)
		{
			n=th(n);
			if(vis[n]) 
			{
				flag=1;
				break;
			}
			vis[n]=1;
		}
		if(flag) cout<<"No";
		else cout<<"Yes";
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

