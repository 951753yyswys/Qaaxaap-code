//感觉好像 2025 CSP-J T3，不难
#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	void work()
	{
		int n,q;
		cin>>n>>q;
		vector<int> a(n),prf(n),lst(n),cnt0(n);
		for(auto &tmp:a) cin>>tmp;
		vector<map<int,int>> ed(2);
		ed[0][a[0]]=1;
		prf[0]=a[0];
		lst[0]=(a[0]==0)-1;
		cnt0[0]=(a[0]==0);
		for(int i=1;i<n;i++)
		{
			cnt0[i]=cnt0[i-1]+(a[i]==0);
			prf[i]=prf[i-1]^a[i];
			lst[i]=ed[(i&1)^1][prf[i]];
			ed[i&1][prf[i]]=i+1;
		}
		while(q--)
		{
			int l,r,xl=0,c0=0;
			cin>>l>>r;
			l--,r--;
			if(l>0) xl=prf[l-1],c0=cnt0[l-1];
			if(prf[r]^xl){cout<<-1<<endl;continue;}
			if(cnt0[r]-c0==r-l+1){cout<<0<<endl;continue;}
			if((r-l+1)%2==1){cout<<1<<endl;continue;}
			if(a[l]==0||a[r]==0){cout<<1<<endl;continue;}
			if(lst[r]>l) cout<<2<<endl;
			else cout<<-1<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

