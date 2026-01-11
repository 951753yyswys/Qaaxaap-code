#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	struct node 
	{
		int val,len;
		vector<int> pt;
		node(){pt.resize(55);}
	};
	struct cmp
	{
		bool operator()(const node& a,const node& b) const
		{
			return a.val>b.val;
		}
	};
	void work()
	{
		int n,k,x;
		cin>>n>>k>>x;
		vector<int> a(n);
		for(auto &tmp:a) cin>>tmp;
		sort(a.rbegin(),a.rend());
		if(n==1)
		{
			cout<<a[0]*k;
			return;
		}
		int m=n-1;
		vector<int> d(m);
		for(int i=0;i<m;i++) d[i]=a[i]-a[i+1];
		int b=a[0]*k;
		priority_queue<node,vector<node>,cmp> pq;
		node rt;
		rt.val=0;
		rt.len=0;
		pq.push(rt);
		int prt=0;
		while(prt<x)
		{
			node now=pq.top();
			pq.pop();
			cout<<b-now.val<<endl;
			prt++;
			int len=now.len;
			if(len>0)
			{
				int lst=now.pt[len-1];
				if(lst<k)
				{
					bool flag=1;
					if(len>=2) if(now.pt[len-2]<lst+1) flag=0;
					if(flag)
					{
						node nxt=now;
						nxt.pt[len-1]=lst+1;
						nxt.val+=d[len-1];
						pq.push(nxt);
					}
				}
			}
			if(len<m)
			{
				node nxt=now;
				nxt.pt[len]=1;
				nxt.len=len+1;
				nxt.val+=d[len];
				pq.push(nxt);
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

