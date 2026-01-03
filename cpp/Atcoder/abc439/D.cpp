#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	void work()
	{
		int n;
		cin>>n;
		vector<int> a(n);
		for(auto &tmp:a) cin>>tmp;
		int ans=0;
		map<int,int> buc;
		for(auto tmp:a)
		{
			if(tmp%5==0) ans+=buc[tmp/5*3]*buc[tmp/5*7];
			buc[tmp]++;
		}
		buc.clear();
		for(int i=n-1;i>=0;i--)
		{
			int tmp=a[i];
			if(tmp%5==0) ans+=buc[tmp/5*3]*buc[tmp/5*7];
			buc[tmp]++;
		}
		cout<<ans;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

