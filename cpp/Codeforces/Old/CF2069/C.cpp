#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int a[201010],ls[202020],s3[202020],s1[202020];
signed main()
{
    int t;
    cin>>t;
    //for(int i=1;i<=10;i++) cout<<ls[i]<<' ';
    //cout<<endl;
    while(t--)
    {
        int n;
        cin>>n;
        s3[0]=0,s1[0]=0;
        for(int i=1;i<=n;i++) 
        {
            cin>>a[i];
            s3[i]=s3[i-1],s1[i]=s1[i-1];
            if(a[i]==3) s3[i]++;
            if(a[i]==1) s1[i]++;
        }
        int ans=0,lt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1) lt=(lt+1)%mod;
            if(a[i]==2) lt=(lt*2)%mod;
            if(a[i]==3) ans=(ans+lt-s1[i]+mod)%mod;
            //cout<<lt<<' ';
        }
        //cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}