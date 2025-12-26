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
			int n,k;
			cin>>n>>k;
			vector<int> p(n+1),d(n+1),vis(n*2+1);
			for(int i=1;i<=n;i++) cin>>p[i];
			for(int i=1;i<=n;i++) cin>>d[i];
			map<int,int> zb,fb,qu;
			vector<pair<int,int>> nxt(n+1);
			vector<vector<int>> mp(n*2+1);
			for(int i=1;i<=n;i++)
			{
				nxt[i].first=zb[(p[i]+d[i])%k];
				if(nxt[i].first) mp[nxt[i].first+n].push_back(i);
				else mp[0].push_back(i);
				zb[(p[i]+d[i])%k]=i;
			}
			for(int i=n;i>=1;i--) 
			{	
				nxt[i].second=fb[(p[i]-d[i]+k)%k];
				mp[nxt[i].second].push_back(i+n);
				fb[(p[i]-d[i]+k)%k]=i;
			}
			queue<int> q;
			q.push(0);
			while(!q.empty())
			{
				int u=q.front();
				q.pop();
				if(vis[u]) continue;
				vis[u]=1;
				for(auto v:mp[u]) q.push(v);
			}	
			int qa;
			cin>>qa;
			vector<pair<int,int>> a(qa);
			vector<int> ans(qa);
			int cnt=0;
			for(auto &tmp:a) cin>>tmp.first,tmp.second=cnt++;cnt=n;
			sort(a.rbegin(),a.rend());
			for(auto [qus,id]:a)
			{
				while(cnt>0&&p[cnt]>=qus) qu[(p[cnt]-d[cnt]+k)%k]=cnt,cnt--;
				ans[id]=vis[qu[qus%k]];
			}
			for(auto tmp:ans)
			{
				if(tmp) cout<<"Yes"<<endl;
				else cout<<"No"<<endl;
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

