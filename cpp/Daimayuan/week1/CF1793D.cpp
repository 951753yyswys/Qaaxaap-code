#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	const int N=5e5+5,mod=998244353;
	void work()
	{
		int n;
		cin>>n;
		vector<int> p(n+1),q(n+1),invp(n+1),invq(n+1);
		for(int i=1;i<=n;i++) cin>>p[i],invp[p[i]]=i;
		for(int i=1;i<=n;i++) cin>>q[i],invq[q[i]]=i;
		int lp=invp[1],rp=lp,lq=invq[1],rq=lq,ans=0;
		for(int i=1;i<n;i++)
		{
			lp=min(lp,invp[i]);
			rp=max(rp,invp[i]);
			lq=min(lq,invq[i]);
			rq=max(rq,invq[i]);
			int mlq=0,mrq=0,mlp=0,mrp=0;
			if(invp[i+1]<lp) mlp=invp[i+1]+1,mrp=n;
			if(invp[i+1]>rp) mlp=1,mrp=invp[i+1]-1;
			if(invq[i+1]<lq) mlq=invq[i+1]+1,mrq=n;
			if(invq[i+1]>rq) mlq=1,mrq=invq[i+1]-1;
			int zz,zy;
			//cout<<lp<<' '<<rp<<endl;
			//cout<<lq<<' '<<rq<<endl;
			//cout<<mlp<<' '<<mrp<<endl;
			//cout<<mlq<<' '<<mrq<<endl;
			//cout<<endl;
			zz=max(0ll,min(lp,lq)-max(mlp,mlq)+1);
			zy=max(0ll,min(mrp,mrq)-max(rp,rq)+1);
			//cout<<"zz:"<<zz<<endl;
			//cout<<"zy:"<<zy<<endl;
			ans+=zz*zy;
		}
		int mi=min(invp[1],invq[1]);
		int mx=max(invp[1],invq[1]);
		ans+=max(0ll,(mi-1)*(mi)/2+(n-mx)*(n-mx+1)/2+(mx-mi-1)*(mx-mi)/2);
		ans++;
		cout<<ans<<endl;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return Qaaxaap::work(),0;
}

