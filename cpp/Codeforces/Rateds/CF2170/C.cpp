#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    void work()
    {
        int T;
        cin>>T;
        while(T--)
        {
            int n,k;
            cin>>n>>k;
            vector<int> q(n),r(n);
            for(auto &tmp:q) cin>>tmp;
            for(auto &tmp:r) cin>>tmp;
            sort(q.rbegin(),q.rend());
            sort(r.begin(),r.end());
            int ans=0,iq=0,ir=0;
            while(iq<n&&ir<n)
            {
                while(iq<n&&(q[iq]*(r[ir]+1)+r[ir]>k)) iq++;
                if(iq>=n) break;
                iq++;
                ans++;
                ir++;
            }
            cout<<ans<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}