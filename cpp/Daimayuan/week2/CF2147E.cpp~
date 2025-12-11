#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	const int N=5e5+5,mod=998244353;
	int gbit(int x,int b)
	{
		return x&(1ll<<b);
	}
	int dbit(int x,int b)
	{
		return x%(1ll<<b+1);
	}
	void work()
	{
		int t;
		cin>>t;
		while(t--)
		{
			int n,q,orans=0;
			cin>>n>>q;
			vector<int> a(n),opt;
			for(auto &tmp:a) cin>>tmp,orans|=tmp;
			int num=0; 
			for(int i=0;i<=31;i++) if(!gbit(orans,i)) opt.push_back(i);
			int yans=__builtin_popcountll(orans);
			vector<int> ans(35);
			for(auto tmp:opt)
			{
				vector<int> atmp(n);
				for(int i=0;i<n;i++) atmp[i]=dbit(a[i],tmp);
				int mx=*max_element(atmp.begin(),atmp.end());
				for(int i=0;i<n;i++) if(mx==atmp[i]) 
				{
					a[i]=0;
					break;
				}
				ans[++yans]=(1ll<<yans)-mx+ans[yans-1];
			}
			for(int i=0;i<=15;i++)
			{
				cout<<"i:"<<i<<" ans[i]"<<ans[i]<<endl;
			}
			while(q--)
			{
				int b;
				cin>>b;
				int ansl=0;
				for(int i=0;i<=33;i++)
				{
					if(b>=ans[i]) ansl=i;
					else break;
				}
				cout<<ansl<<endl;
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return Qaaxaap::work(),0;
}

