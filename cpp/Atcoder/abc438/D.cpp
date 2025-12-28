#include<bits/stdc++.h>
#define int long long
using namespace std;

namespace Qaaxaap
{
    void work()
    {
        int n;
        cin>>n;        
        vector<int> a(n),b(n),c(n);
        for(auto &tmp:a) cin>>tmp;
        for(auto &tmp:b) cin>>tmp;
        for(auto &tmp:c) cin>>tmp;
        vector<int> pfa(n+1),pfb(n+1),pfc(n+1);
        for(int i=1;i<=n;i++) 
        {
            pfa[i]=pfa[i-1]+a[i-1];
            pfb[i]=pfb[i-1]+b[i-1];
            pfc[i]=pfc[i-1]+c[i-1];
        }
        int ans=-100000000000000ll;
        vector<int> pfs(n+1,-100000000000000ll);
        for(int y=n-1;y>=2; y--) pfs[y]=b[y-1]+max(pfs[y+1],pfc[n]-pfc[y]);
        for(int x=1;x<=n-1;x++) ans=max(ans,pfa[x]+pfs[x+1]);
        cout<<ans<<endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Qaaxaap::work(), 0;
}
