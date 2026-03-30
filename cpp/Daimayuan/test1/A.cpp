#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace Qaaxaap
{
    void work()
    {
        int n;
        cin>>n;
        vector<int> a(n+1),prefix(n+1);
        for(int i=1;i<=n;i++) cin>>a[i],prefix[i]=prefix[i-1]+a[i];
        int flag=0;
        for(int i=1;i<=n;i++) if(prefix[i]<0) flag=1;
        if(flag)
        {
            cout<<-1;
            return;
        }
        int cnt=0,ans=0;
        for(int i=n;i>=1;i--)
        {
            cnt+=a[i];
            if(cnt>=0) ans++,cnt=0;
        }
        cout<<ans;
    }
};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return Qaaxaap::work(),0;
}