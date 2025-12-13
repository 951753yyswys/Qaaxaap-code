#include <bits/stdc++.h>
#define int long long
#define sor(i,l,r) for(int i=l;i<=r;++i)
#define ros(i,r,l) for(int i=r;i>=l;--i)
using namespace std;
namespace Qaaxaap
{
    constexpr const int N = 5e5 + 5, P = 998244353;
    int T,n,a[N];
    inline void work()
    {
        cin>>n;
        sor(i,1,n) cin>>a[i];
        int cnt=0;
        sor(i,1,n)
        {
            if(abs(a[i])>=10) cnt++; 
        }
        if(n<=2&&abs(a[1]+a[2])<10) cout<<0;
        else cout<<cnt;
    }
}
signed main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return Qaaxaap::work(), 0;
}