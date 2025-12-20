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
			int n,w;
			cin>>n>>w;
			vector<int> fa(n+5),dep(n+5),ll(n+5),lll(n+5),len(n+5);
			for(int i=2;i<=n;i++) cin>>fa[i];
			for(int i=2;i<=n;i++) dep[i]=dep[fa[i]]+1;
			for(int i=1;i<=n;i++) len[i]=ll[i]=0;
			for(int i=1,x,y;i<=n;i++) 
			{
				x=i;
				if(i==n) y=1;
				else y=i+1;
				while(x!=y) 
				{
					if(dep[x]<dep[y]) swap(x,y);
					if(ll[x]) lll[x]=i;
					else ll[x]=i;
					x=fa[x],++len[i];
				}
			}
			int sum=0,now=n;
			for(int i=1,x;i<n;i++) 
			{
				cin>>x;
				int tmp;
				cin>>tmp;
				sum+=tmp;
				if((--len[ll[x]])==0) --now;
				if((--len[lll[x]])==0) --now;
				cout<<(sum*2+now*(w-sum))<<' ';
			}
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
