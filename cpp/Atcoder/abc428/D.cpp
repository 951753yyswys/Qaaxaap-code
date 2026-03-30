#include<bits/stdc++.h>
#define i1 __int128
#define ll long long
using namespace std;
ll p10[16];
void pre() 
{
    p10[0]=1;
    for(int i=1;i<=15;i++)
        p10[i]=p10[i-1]*10;
}
int main() 
{
    pre();
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--) 
    {
        ll C,D;
        cin>>C>>D;
        ll nmi=C+1;
        ll nmx=C+D;
        int dmi=0,dmx=0;
        ll t1=nmi;
        while(t1) 
        {
            dmi++;
            t1/=10;
        }
        ll t2=nmx;
        while(t2) 
        {
            dmx++;
            t2/=10;
        }
        ll ans=0;
        for(int d=dmi;d<=dmx;d++) 
        {
            ll lod=max(p10[d-1],nmi);
            ll hid=min(p10[d]-1,nmx);
            if(lod>hid) continue;
            i1 L=(i1)C*p10[d]+lod;
            i1 R=(i1)C*p10[d]+hid;
            ll kmi=-1,kmx=-1;
            ll left=0,right=2000000000;
            while(left<=right) 
            {
                ll mid=(left+right)/2;
                if((i1)mid*mid>=L) 
                {
                    kmi=mid;
                    right=mid-1;
                } 
                else left=mid+1;
            }
            left=0,right=2000000000;
            while(left<=right) 
            {
                ll mid=(left+right)/2;
                if((i1)mid*mid<=R) 
                {
                    kmx=mid;
                    left=mid+1;
                } 
                else right=mid-1;
            }
            if(kmi!=-1&&kmx!=-1&&kmi<=kmx) ans+=(kmx-kmi+1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}