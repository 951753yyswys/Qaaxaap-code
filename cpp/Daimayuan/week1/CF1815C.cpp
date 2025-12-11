#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	const int N=5e5+5,mod=998244353;
	void work()
	{
		int t;
		cin>>t;
		while(t--)
		{
			int n,m;
			cin>>n>>m;
			if(n==1)
			{
				cout<<"FINITE"<<endl;
				cout<<1<<endl<<1<<endl;
				continue;
			}
			vector<int> dep(n+1,-1);
			vector<vector<int>> son(n+1),kaola(n+1);
			for(int i=1;i<=m;i++)
			{
				int a,b;
				cin>>a>>b;
				son[b].push_back(a);
			}
			int bl=1,mx=0;
			queue<int> q;
			q.push(1);
			dep[1]=0;
			kaola[0].push_back(1);
			while(!q.empty())
			{
				int u=q.front();
				q.pop();
				for(auto v:son[u]) if(dep[v]==-1) bl++,dep[v]=dep[u]+1,kaola[dep[v]].push_back(v),q.push(v),mx=max(mx,dep[v]);
			}
			if(bl<n) 
			{
				cout<<"INFINITE"<<endl;
				continue;
			}
			vector<int> ans;
			for(auto tmp:kaola[mx]) ans.push_back(tmp);
			for(int i=mx-1;i>=0;i--) for(int j=i;j<=mx;j++) for(auto tmp:kaola[j]) ans.push_back(tmp);
			cout<<"FINITE"<<endl;
			cout<<ans.size()<<endl;
			for(auto tmp:ans) cout<<tmp<<' ';
			cout<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return Qaaxaap::work(),0;
}

