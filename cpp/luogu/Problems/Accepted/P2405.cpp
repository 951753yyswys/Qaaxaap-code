#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5;
    int qp(int d,int z,int mod)
    {
        int t=1;
        while(z)
        {
            if(z&1) t=t*d%mod;
            d=d*d%mod;
            z>>=1;
        }
        return t;
    }
    int BSGS(int y,int z,int mod)
    {
        if((y%mod==0)^(z%mod==0)) return -1;
        if(y%mod==z%mod) return (bool)(z!=1);
        unordered_map<int,int> mp;
        int mx=ceil(sqrt(mod)),len=qp(y,mx,mod);
        int lst=z;
        mp[z]=1;
        for(int i=1;i<=mx;i++)
        {
            lst=lst*y%mod;
            mp[lst]=i+1;
        }
        lst=1;
        int ans=-1;
        for(int i=0;i<=mx;i++)
        {
            if(mp[lst]) 
            {
                if(mx*i-mp[lst]+1<0) continue;
                ans=mx*i-mp[lst]+1;
                break;
            }
            lst=lst*len%mod;
        }
        return ans;
    }
    void work()
    {
        int t,k;
        cin>>t>>k;
        if(k==1)
        {
            while(t--)
            {
                int y,z,m;
                cin>>y>>z>>m;
                cout<<qp(y,z,m)<<endl;
            }
        }
        if(k==2)
        {
            while(t--)
            {
                int y,z,m;
                cin>>y>>z>>m;
                if(y%m==0&&z%m!=0) cout<<"Orz, I cannot find x!"<<endl;
                else cout<<z*qp(y,m-2,m)%m<<endl;
            }
        }
        if(k==3)
        {
            while(t--)
            {
                int y,z,m;
                cin>>y>>z>>m;
                int ans=BSGS(y,z,m);
                if(ans==-1) cout<<"Orz, I cannot find x!"<<endl;
                else cout<<ans<<endl;
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