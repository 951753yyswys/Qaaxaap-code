#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int sw(int x)
{
    queue<int> tmp;
    while(x>0) 
    {
        tmp.push(x%10);
        x/=10;
    }
    while(!tmp.empty())
    {
        x*=10;
        x+=tmp.front();
        tmp.pop();
    }
    return x;
}
int qp(int d,int z,int mod)
{
    int t=1;
    while(z)
    {
        if(z&1) t=t*d%mod;
        d=d*d%mod; 
        z>>=1;
    }
    return t;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int l,r,a,b,c;
        cin>>l>>r>>a>>b>>c;
        int ans=0;
        for(int i=0;i<b;i++)
        {
            if(i%10==0) continue;
            int fb=sw(i);
            while(fb<=1e18)
            {
                int fx=fb-c;
                //cout<<fx<<endl;
                if(fx<0)
                {
                    fb*=10;
                    if(fb==0) break;
                    continue;
                }
                if(fx%10==0)
                {
                    fb*=10;
                    continue;
                }
                int x=sw(fx);
                while(x<=r)
                {
                    //cout<<x<<endl;
                    if(x<l)
                    {
                        x*=10;
                        if(x==0) break;
                        continue;
                    }
                    if(qp(x,a,b)==i) ans++;//cout<<x<<endl;
                    x*=10;
                }
                fb*=10;
            }
        }
        cout<<ans<<endl;
    } 
    return 0;
}