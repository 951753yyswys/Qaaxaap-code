#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
namespace Qaaxaap
{
	class pl
	{
	public:
		int s,t,d,v;
		pl(int S,int T,int D)
		{
			s=S;t=T;d=D;
			v=t-s;
		}
	};
	int ab(int x)
	{
		if(x<0) x=x*(-1ll);
		return x;
	}
	void work()
	{
		int n,d;
		cin>>n>>d;
		vector<pl> a;
		for(int i=1;i<=n+1;i++)
		{
			int s,t,d;
			cin>>s>>t>>d;
			a.push_back(pl(s,t,d));
		}
		int rs=a[0].s,rt=a[0].t,rd=a[0].d,rv=a[0].v;
		for(int i=1;i<=n;i++)
		{
			if(ab(rd-a[i].d)>d) 
			{
				cout<<"No"<<endl;
				continue;
			}
			if(rs==a[i].s&&rv==a[i].v) 
			{
				cout<<"Always"<<endl;
				continue;
			}
			if(rv==a[i].v)
			{
				cout<<"No"<<endl;
				continue;
			}
			double ans=rs+rv*1.0*((a[i].s-rs)*1.0/(rv-a[i].v));
			if(ans>max(rt,rs)||ans<min(rt,rs)||ans<min(a[i].t,a[i].s)||ans>max(a[i].t,a[i].s)) 
			{
				cout<<"No"<<endl;
				continue;
			}
			cout<<fixed<<setprecision(12)<<ans<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

