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
            int n;
            cin>>n;
            vector<int> a(n*n);
            for(auto &tmp:a) cin>>tmp;
            sort(a.rbegin(),a.rend());
            int ans=0;
            for(int i=0;i<n;i++) ans+=a[i];
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