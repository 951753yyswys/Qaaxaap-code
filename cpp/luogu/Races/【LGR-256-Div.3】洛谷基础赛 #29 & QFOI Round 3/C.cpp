#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	void work()
	{
		int n,k,d;
		cin>>n>>k>>d;
		vector<int> a(n);
		for(auto &tmp:a) cin>>tmp;
		int mi=a[0],cnt=0,ans=1;
		sort(a.begin(),a.end());
		mi=a[0];
		if(d==0) 
		{
			for(auto tmp:a) 
			{
				if(mi!=tmp||cnt>=k) ans++,mi=tmp,cnt=1;
				else cnt++;
			}
		}
		else 
		{
			int i=0,j=0;
			ans=0;
			while(i<n)
			{
				ans++;
				int len=1,nd=0;
				j=i+1;
				while(j<n)
				{
					if(len+1+nd+(a[j]-a[j-1]-1)/d<=k)
					{
						len++;
						nd+=(a[j]-a[j-1]-1)/d;
						j++;
					}
					else break;
				}
				i=j;
			}
		}
		cout<<ans*k-n;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}
	
