#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace Qaaxaap
{
    const int mod=998244353,N=5e3+5;
    void work()
    {
        int n,k;
        cin>>n>>k;
        vector<vector<int>> a(n+1);
        vector<int> l(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>l[i];
            int tmp;
            for(int j=1;j<=l[i];j++) cin>>tmp,a[i].push_back(tmp%mod);
        }
        int ans=0;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        {
            int g=__gcd(l[i],l[j]);
            vector<int> d(g);
            for(int k=0;k<l[j];k++) d[k%g]=(d[k%g]+a[j][k])%mod;//,cout<<a[j][k]<<endl;
            int lans=0;
            for(int k=0;k<l[i];k++) lans=(lans+d[k%g]*a[i][k]%mod)%mod;
            lans*=k/(l[i]*l[j]/g);
            lans%=mod;
            ans=max(ans,lans);
        }
        cout<<ans;
    }
};
signed main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}