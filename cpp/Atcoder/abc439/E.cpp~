#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace DS
{
	class fenw
	{
	public:
		vector<int> t;
		int siz;
		fenw(int n){t.resize(n+1);siz=n;}
		int lowb(int x){return x&-x;}
		void add(int val,int idx)
		{
			while(idx<=siz)
			{
				t[idx]=max(val,t[idx]);
				idx+=lowb(idx);
			}
		}
		int ask(int idx)
		{
			int ret=0;
			while(idx>0)
			{
				ret=max(t[idx],ret);
				idx-=lowb(idx);
			}
			return ret;
		}
	};
}
using namespace DS;
namespace Qaaxaap
{
	bool cmp(pair<int,int> x,pair<int,int> y)
	{
		return x.second<y.second;
	}
	void work()
	{
		int n;
		cin>>n;
		vector<pair<int,int>> a(n);
		for(auto &tmp:a) cin>>tmp.first>>tmp.second;
		map<int,int> ls;
		sort(a.begin(),a.end(),cmp);
		int cnt=0;
		for(auto [x,y]:a) ls[y]=++cnt;
		sort(a.begin(),a.end());
		fenw tr(n);
		int lst=-1;
		queue<pair<int,int>> que;
		for(auto [x,y]:a)
		{
			if(x!=lst) 
			{
				while(!que.empty())
				{
					tr.add(que.front().first,que.front().second);
					que.pop();
				}
			}
			int tmp=tr.ask(ls[y]-1);
			que.push({tmp+1,ls[y]});
			lst=x;
		}
		while(!que.empty())
		{
			tr.add(que.front().first,que.front().second);
			que.pop();
		}
		cout<<tr.ask(n);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

