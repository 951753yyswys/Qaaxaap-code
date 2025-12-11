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
            vector<int> a(2*n),cnt(n*2+1);
            for(auto &tmp:a) cin>>tmp,cnt[tmp]++;
            int ans=0,cnt1=0,cnt2=0,suml=0,sumr=0,flag=0;
            for(int i=1;i<=2*n;i++)
            {
                if(cnt[i]<=0) continue;
                if(cnt[i]%2) cnt1++;
                else cnt2++;
                ans+=2-cnt[i]%2;
                if(cnt[i]%2==0) suml++,sumr--;
                else flag=1;
                sumr+=cnt[i];
            }
            if(suml%2!=n%2) ans-=2*(1-flag);
            ans=max(ans,0ll);
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