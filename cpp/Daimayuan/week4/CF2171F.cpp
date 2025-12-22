#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	vector<int> pri;
	int mxp[N];
	void pre(int n)
	{
		mxp[1]=1;
		for(int i=2;i<=n;i++)
		{
			if(!mxp[i]) 
			{
				mxp[i]=i;
				pri.push_back(i);
			}
			for(auto pri_j:pri)
			{
				if(i*pri_j>n) break;
				if(mxp[i*pri_j]==0) mxp[i*pri_j]=pri_j;
				if(i%pri_j==0) break;
			}
		}
	}
	void work()
	{
		pre(202020);
		int t;
		cin>>t;
		while(t--)
		{
			int n;cin>>n;
			vector<int> a(n),pre(n),suf(n),plc(n);
			for(auto &tmp:a) cin>>tmp;
			pre[0]=a[0],suf[n-1]=a[n-1],plc[n-1]=n-1;
			for(int i=1;i<n;i++) pre[i]=min(pre[i-1],a[i]);
			for(int i=n-1;i>0;i--)
			{
				suf[i-1]=suf[i],plc[i-1]=plc[i];
				if(a[i-1]>suf[i]) plc[i-1]=i-1,suf[i-1]=a[i-1];
			}
			bool flag=0;
			for(int i=1;i<n;i++) if(pre[i-1]>suf[i]) flag=1;
			if(flag) 
			{
				cout<<"No"<<endl;
				continue;
			}
			cout<<"Yes"<<endl;
			int j;
			for(int i=0;i<n;i=j+1)
			{
				j=plc[i];
				for(int k=i;k<j;k++) cout<<a[k]<<' '<<a[j]<<endl;
				if(i>0) cout<<pre[i-1]<<' '<<a[j]<<endl;
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

