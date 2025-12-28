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
			int n,m;
			cin>>n>>m;
			vector<int> a(n);
			for(auto &tmp:a) cin>>tmp;
			if(m==n)
			{
				cout<<-1<<endl;
				continue;
			}
			map<int,int> dzd;
			int cnt=0;
			for(auto tmp:a) dzd[tmp]=++cnt;
			sort(a.begin(),a.end());
			vector<pair<int,int>> ans;
			if(m==0)
			{
				if(n<3)
				{
					cout<<-1<<endl;
					continue;
				}
				int sm=0,mx=a[n-1],cmx=a[n-2],opt=dzd[mx];
				for(int i=0;i<n-1;i++) sm+=a[i];
				if(a[n-1]>sm)
				{
					cout<<-1<<endl;
					continue;
				}
				for(int i=0;i<n-3;i++)
				{
					if(cmx<mx-a[i]) ans.push_back({dzd[a[i]],opt}),mx-=a[i];
					else ans.push_back({dzd[a[i]],dzd[a[i+1]]});
				}
				ans.push_back({dzd[a[n-2]],opt});
				ans.push_back({dzd[a[n-3]],opt});
			}
			else 
			{
				if(m>n/2) 
				{
					cout<<-1<<endl;
					continue;
				}
				if(m==1) for(int i=1;i<n;i++) ans.push_back({dzd[a[i-1]],dzd[a[i]]});
				else
				{
					int lk=n-m;
					vector<int> kil;
					for(int i=0;i<m;i++)
					{
						vector<int> gru;
						for(int j=i;j<lk;j+=m) gru.push_back(dzd[a[j]]); 
						for(int j=0;j<gru.size()-1;j++) ans.push_back({gru[j],gru[j+1]});
						kil.push_back(gru.back());
					}
					for(int i=0;i<m;i++) ans.push_back({dzd[a[lk+i]],kil[i]});
				}			
			}
			cout<<ans.size()<<endl;
			for(auto [x,y]:ans) cout<<x<<' '<<y<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

