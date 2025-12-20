#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	struct node
	{
		int num;
		set<int> p;
		map<int,int> son;
	} t[402020];
	int inv[494949];
	void dfs(int u)
	{
		for(auto tmp:t[u].p) cout<<tmp<<' ';
		for(auto tmp:t[u].son) dfs(tmp.second);
	}
	void work()
	{
		int cnt=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) 
		{
			int x,y;
			cin>>x>>y;
			int ys=t[inv[x]].son[y];
			if(ys)
			{
				inv[i]=ys;
				t[ys].p.insert(i);
				continue;
			}
			cnt++;
			t[cnt].num=y;
			t[cnt].p.insert(i);
			inv[i]=cnt;
			t[inv[x]].son[y]=cnt;
		}
		dfs(0);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

