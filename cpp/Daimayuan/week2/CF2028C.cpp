#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace Qaaxaap
{
    int a[1010010],hd[1010010],tl[1010010],sum[1010010];
    inline void work()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int n,m,v;
            cin>>n>>m>>v;
            sum[0]=hd[0]=tl[n+1]=0;
            for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i];
            int num=0;
            for(int i=1;i<=n;i++)
            {
                hd[i]=hd[i-1];
                num+=a[i];
                if(num>=v) hd[i]++,num=0;
            }
            num=0;
            for(int i=n;i>=1;i--)
            {
                tl[i]=tl[i+1];
                num+=a[i];
                if(num>=v) tl[i]++,num=0;
            }
            if(hd[n]<m) 
            {
                cout<<-1<<endl;
                continue;
            }
            int ans=0;
            for(int i=n;i>=1;i--)
            {
                int opt=lower_bound(hd,hd+n+1,m-tl[i+1])-hd;
                if(opt+1>i) continue;
                ans=max(ans,sum[i]-sum[opt]);
            }
            cout<<ans<<endl;
        }  
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return Qaaxaap::work(),0;
} 