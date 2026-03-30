#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    void work()
    {
        int n,m;
        cin>>n>>m;
        vector<int> cnt(m),sum(m);
        for(int i=1;i<=n;i++) 
        {
            int tmp1,tmp2;
            cin>>tmp1>>tmp2;
            cnt[tmp1-1]++;
            sum[tmp1-1]+=tmp2;
        }
        for(int i=0;i<m;i++)
        {
            double ans=sum[i]*1.0/(cnt[i]*1.0);
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