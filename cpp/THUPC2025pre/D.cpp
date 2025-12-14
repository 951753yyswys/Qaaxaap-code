#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	const int N=5e5+5,mod=998244353;
	void work()
	{
		int t;
		cin>>t;
		while(t--)
		{
			int n;
			cin>>n;
			vector<int> x(n),ans(n);
			for(auto &tmp:x) cin>>tmp;
			sort(x.begin(),x.end());
			//int mx=0,ami=(n-1)/2,amx=ami;
			//ans[ami]=x[++mx];
			//while(ami>0&&amx<n-1)
			//{
			//	ans[++amx]=x[mx++];
			//	ans[--ami]=x[mx++];
			//}
			//while(amx<n-1) ans[++amx]=x[mx++];
			//while(ami>0) ans[--ami]=x[mx++];
			//int lans=0;
			//for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) lans+=(j-i)*ans[i]*ans[j];
			//cout<<lans;
			//cout<<endl;
			int mx=0;
			while(1)
			{
				int ans=0;
				for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) ans+=(j-i)*x[i]*x[j];
				if(ans>mx)
				{
					mx=ans;
					cout<<ans<<endl;
					for(auto tmp:x) cout<<tmp<<' ';
					cout<<endl;
				}
				if(!next_permutation(x.begin(),x.end())) break;
			}
			int cmx,cmi;
			if(n%2==1) 
			{
				bool rf=1;
				int mx=0;
				cmx=cmi=n/2;
				ans[cmx]=x[mx++];
				while(cmi>0&&cmi<n-1)
				{
					if(rf)
					{
						ans[++cmx]=x[mx++];
						ans[--cmi]=x[mx++];
						rf^=1;
					}
					else 
					{
						ans[--cmi]=x[mx++];
						ans[++cmx]=x[mx++];
						rf^=1;
					}
				}
			}	
			else 
			{
				int mx=0;
				bool rf;
				cmi=n/2-1;
				cmx=n/2;
				if(n/2%2) rf=1,ans[cmi]=x[mx++],ans[cmx]=x[mx++];
				else rf=0,ans[cmx]=x[mx++],ans[cmi]=x[mx++];
				while(cmi>0&&cmi<n-1)
				{
					if(rf)
					{
						ans[++cmx]=x[mx++];
						ans[--cmi]=x[mx++];
						rf^=1;
					}
					else
					{
						ans[--cmi]=x[mx++];
						ans[++cmx]=x[mx++];
						rf^=1;
					}
				}
			}
			//for(auto tmp:ans) cout<<tmp<<' ';
			//cout<<endl;
			int sum=0;
			for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) sum+=(j-i)*ans[j]*ans[i];
			//cout<<sum<<endl;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	return Qaaxaap::work(),0;
}

