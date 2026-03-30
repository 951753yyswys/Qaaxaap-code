#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    void work1()
    {
        //WA on #2
        int T;
        cin>>T;
        while(T--)
        {
            int n,k;
            cin>>n>>k;
            vector<int> a(n),b(n),dp1(n),dp0(n);
            for(auto &tmp:a) cin>>tmp;
            for(auto &tmp:b) cin>>tmp;
            dp0[0]=max(0ll,a[0]);
            dp1[0]=max(0ll,a[0]+b[0]);
            int mx1=-0x7fffffffffffffff,mx0=-0x7fffffffffffffff;
            for(int i=0;i<n;i++) mx0=max(mx0,a[i]),mx1=max(mx1,a[i]+b[i]);
            for(int i=1;i<n;i++)
            {
                dp0[i]=max(0ll,dp0[i-1]+a[i]);
                dp1[i]=max(dp0[i-1]+a[i]+b[i],dp1[i-1]+a[i]);
                mx0=max(mx0,dp0[i]);
                mx1=max(mx1,dp1[i]);
                dp1[i]=max(0ll,dp1[i]);
            }
            if(k%2) cout<<mx1<<endl;
            else cout<<mx0<<endl;
        }
    }
    void work()
    {
        int T;
        cin>>T;
        while(T--)
        {
            int n,k;
            cin>>n>>k;
            vector<int> a(n),b(n);
            for(auto &tmp:a) cin>>tmp;
            for(auto &tmp:b) cin>>tmp;
            vector<int> pre(n),suf(n);
            int now=a[0];
            pre[0]=now;
            for(int i=1;i<n;i++) 
            {
                now=max(a[i],now+a[i]);
                pre[i]=now;
            }
            now=a[n-1];
            suf[n-1]=now;
            for(int i=n-2;i>=0;i--) 
            {
                now=max(a[i],now+a[i]);
                suf[i]=now;
            }
            vector<int> ans(n);
            int lans=-0x7fffffffffffffff;
            for(int i=0;i<n;i++) 
            {
                ans[i]=pre[i]+suf[i]-a[i]; 
                lans=max(lans,ans[i]);
            }
            if(k%2)
            {
                int kans=-0x7fffffffffffffff;
                for(int i=0;i<n;i++) kans=max(kans,ans[i]+b[i]);
                cout<<kans<<endl;
            }
            else cout<<lans<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}