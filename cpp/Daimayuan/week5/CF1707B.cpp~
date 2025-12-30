#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	void work()
	{
		int t;
		cin>>t;
		while(t--)
		{
			int n,cn0=0;
			cin>>n;
			vector<int> a(n),b;
			for(auto &tmp:a) cin>>tmp;
			for(int i=1;i<=n-1;i++)
			{
				b.clear();
				if(cn0) b.push_back(a[0]);
				if(cn0) cn0--;
				for(int i=1;i<a.size();i++) 
				{
					if(a[i]-a[i-1]) b.push_back(a[i]-a[i-1]);
					else cn0++;
				}
				if(b.size()<=1)
				{
					if(b.empty()) a[0]=0;
					else a[0]=b[0];
					break;
				}
				sort(b.begin(),b.end());
				a=move(b);	
				//for(int i=1;i<=cn0;i++) a.push_back(0);
			}
			cout<<a[0]<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	return Qaaxaap::work(),0;
}

