#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int g=__gcd(n,m);
        n/=g;
        m/=g;
        if(m!=(1<<((int)(log2(m))))) 
        {
            cout<<-1<<endl;
            continue;
        }
        n*=g,m*=g;
        int cnt=0;
        int ans=0,k=n%m;
        while(k%m!=0)
        {
            ans+=k;
            k*=2;
            k%=m;
            cnt++;
        }
        cout<<ans<<endl;
    }
}