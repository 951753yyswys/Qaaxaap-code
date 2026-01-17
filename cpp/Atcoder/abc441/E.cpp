#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Ds
{
	class Fenwick 
	{
	public:
		int n;
		vector<int> t;
		Fenwick(int n=0):n(n),t(n+1,0){}
		int lowbit(int x){return x&-x;}
		void add(int pl,int v) 
		{ 
			while(pl<=n) t[pl]+=v,pl+=lowbit(pl);
		}
		int sum(int pl) 
		{
			int r=0;
			while(pl>0) r+=t[pl],pl-=lowbit(pl);
			return r;
		}
	};
}
using namespace Ds;
namespace Qaaxaap
{
	void work()
	{
		int n;
		string s;
		cin >> n >> s;
		vector<int> prf(n+1,0);
		for(int i=1;i<=n;i++) 
		{
			char c=s[i-1];
			int v=0;
			if(c=='A') v=1;
			else if(c=='B') v=-1;
			else v=0; 
			prf[i]=prf[i-1]+v;
		}
		vector<int> xs=prf;
		sort(xs.begin(),xs.end());
		xs.erase(unique(xs.begin(),xs.end()),xs.end());
		Fenwick fw(xs.size());
		int ans=0;
		for(int i=0;i<=n;i++) 
		{
			int id=lower_bound(xs.begin(),xs.end(),prf[i])-xs.begin()+1; 
			ans+=fw.sum(id-1);
			fw.add(id,1);
		}
		cout<<ans<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

