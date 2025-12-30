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
			int n,m,k,sy=0;
			cin>>n>>m>>k;
			vector<int> bx(m);
			for(auto &tmp:bx) cin>>tmp;
			sort(bx.begin(),bx.end());
			vector<pair<int,int>> fr(n);
			for(auto &tmp:fr)
			{
				int x,y,z;
				cin>>x>>y>>z;
				sy+=y;
				tmp={x,z-y};
			}
			int e=k-sy;
			vector<int> od(n);
			int lcnt=0;
			for(auto &tmp:od) tmp=lcnt++;
			sort(od.begin(),od.end(),[&](int i,int j){return fr[i].first<fr[j].first;});
			vector<int> vis(n);
			priority_queue<pair<int,int>> pq;
			int p=0,ans=0;
			for(int tmp:bx)
			{
				while(p<n&&fr[od[p]].first<=tmp)
				{
					int idx=od[p++];
					pq.push({fr[idx].second,idx});
				}
				if(!pq.empty())
				{
					auto [d,idx]=pq.top();
					pq.pop();
					if(!vis[idx])
					{
						vis[idx]=1;
						ans++;
					}
				}
			}
			vector<int> c;
			for(int i=0;i<n;i++) if(!vis[i]) c.push_back(fr[i].second);
			sort(c.begin(),c.end());
			int sp=0;
			for(int tmp:c)
			{
				if(sp+tmp<=e)
				{
					sp+=tmp;
					ans++;
				}
				else break;
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

