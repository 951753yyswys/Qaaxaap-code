#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
namespace DS
{
	class fenw
	{
	public:
		vector<int> t;
		int siz;
		fenw(int n){t.assign(n+1,0);siz=n;}
		int lowb(int x){return x&-x;}
		void add(int val,int idx)
		{
			while(idx<=siz)
			{
				t[idx]+=val;
				if(t[idx]>=mod) t[idx]-=mod;
				idx+=lowb(idx);
			}
		}
		int ask(int idx)
		{
			int ret=0;
			while(idx>0)
			{
				ret+=t[idx];
				if(ret>=mod) ret-=mod;
				idx-=lowb(idx);
			}
			return ret;
		}
	};
}
using namespace DS;
namespace Qaaxaap
{
	void work()
	{
		int n;
		cin>>n;
		vector<int> p(n+1);
		for(int i=1;i<=n;i++) cin>>p[i];
		vector<int> pow2(n+1),inp2(n+1);
		pow2[0]=1;
		for(int i=1;i<=n;i++) pow2[i]=pow2[i-1]*2%mod;
		int inv2=(mod+1)/2;
		inp2[0]=1;
		for(int i=1;i<=n;i++) inp2[i]=inp2[i-1]*inv2%mod;
		vector<int> a(n+1),b(n+1);
        fenw tr1(n);
        for(int i=1;i<=n;i++)
        {
            a[i]=tr1.ask(p[i]-1);
            tr1.add(1,p[i]);
        }
        fenw tr2(n);
        for(int i=n;i>=1;i--)
        {
            b[i]=tr2.ask(p[i]-1);
            tr2.add(1,p[i]);
        }
		int ans=0;
		for(int i=1;i<=n;i++) ans=(ans+a[i]*b[i])%mod;
		int prf=0;
		for(int l=1;l<=n;l++)
		{
			ans=(ans+b[l]*pow2[l-1]%mod*prf)%mod;
			prf=(prf+a[l]*inp2[l])%mod;
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

