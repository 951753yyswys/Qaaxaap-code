//喜闻乐见的 bitset 乱搞，n^3 暴力硬除以一个 w，算着是能过
//差分写错了（？？？
#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	const int N=5e5+5,mod=998244353;
	void work()
	{
		int n,m;
		cin>>n>>m;
		vector<vector<int>> g(n+1);
		vector<bitset<767>> b(n+1);
		for(int i=1;i<=m;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++) 
		{
			for(auto v:g[i]) b[i][v]=1;
			b[i][i]=1;
		}
		int ans=0x7fffffff;
		vector<int> vis(n+5);
		for(int i=1;i<=n;i++)
		{
			if(b[i].count()==n)
			{	
				ans=min(ans,n*(n-1)/2); 
				vis[n]=1;
				continue;
			}
			for(int j=i+1;j<=n;j++)
			{
				if(b[j].count()==n) continue;
				bitset<767> temp;
				temp=b[i]|b[j];
				if(temp.count()==n) 
				{
					temp=b[i]&b[j];
					int flag=b[i][j];
					int free=temp.count();
					free-=flag;
					int mxc=max(b[i].count(),b[j].count());
					int mic=min(b[i].count(),b[j].count());
					vis[mxc-free]+=1,vis[mxc+1]-=1;
					vis[mic-free]+=1,vis[mic+1]-=1;					
				}
			}
		}
		for(int i=1;i<=n;i++) vis[i]+=vis[i-1];
		for(int i=0;i<=n;i++) if(vis[i]) ans=min(ans,i*(i-1)/2+(n-i)*(n-i-1)/2);
		if(ans==0x7fffffff) ans=-1;
		cout<<ans<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return Qaaxaap::work(),0;
}

