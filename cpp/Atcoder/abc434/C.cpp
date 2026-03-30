#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    void work()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int n,h,l,r;
            cin>>n>>h;
            l=h,r=h;
            bool flag=1;
            int lst=0;
            for(int i=1;i<=n;i++)
            {
                int t,mi,mx;
                cin>>t>>mi>>mx;
                l=max(l-t+lst,1ll);
                r+=t-lst;
                lst=t;
                if(l<=r&&r>=mi&&l<=mx) 
                {
                    l=max(l,mi);
                    r=min(mx,r);
                }
                else flag=0;
            }
            if(flag) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}