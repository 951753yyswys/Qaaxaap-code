#include<bits/stdc++.h>
#define sor(i,l,r) for(int i=l;i<=r;i++)
//#define int unsigned long long
#define int __int128
using namespace std;
namespace Revitalize
{
    void pri(__int128 x)
    {
        stack<signed> tmp;
        while(x!=0)
        {
            tmp.push(x%10);
            x/=10;
        }
        while(!tmp.empty())
        {
            cout<<tmp.top();
            tmp.pop();
        }
    }
    const long long N=5e5;
    long long T,n,k;
    int w[N],l[N],t[N];
    bool check(int mid)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            cnt+=(mid/(l[i]*t[i]+w[i]))*l[i];
            cnt+=min((__int128)l[i],(mid%(l[i]*t[i]+w[i]))/t[i]);
        }
        return (cnt>=k);
    }
    inline void work(){
        cin>>T;
        while(T--)
        {
            cin>>n>>k;
            for(int i=1;i<=n;i++)
            {
                long long llt,lll,llw;
                cin>>llt>>lll>>llw;
                t[i]=llt;
                l[i]=lll;
                w[i]=llw;       
            }
            int ll=0,r=1e30,ans=0;
            //cout<<check(25)<<"\n";
            while(ll<=r)
            {
                int mid=(ll+r)>>1;
                //cout<<mid<<" ";
                if(check(mid))
                {
                    ans=mid;
                    r=mid-1;
                }
                else{
                    ll=mid+1;
                }
            }
            sor(i,1,n) t[i]=l[i]=w[i]=0;
            pri(ans);
            cout<<'\n';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    return Revitalize::work(),0;
}