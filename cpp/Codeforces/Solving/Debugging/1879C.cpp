#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define int long long
int hw[202020];
int qp(int d,int z)
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
int A(int n,int m)
{
    return hw[n]*qp(hw[n-m],mod-2)%mod;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    hw[0]=1;
    for(int i=1;i<=200020;i++) hw[i]=(hw[i-1]*i)%mod;
    while(t--)
    {
        int suml=0;
        int ans=1;
        string s;
        cin>>s;
        s='#'+s;
        s=s+'#';
        int ls=s[1]-'0',len=0,lens=0;
        for(int i=1;i<s.size();i++)
        {
            if(ls==s[i]-'0') len++;
            else 
            {
                if(len>1)
                {
                    suml+=len-1;
                    lens+=len;
                    lens--;
                    ans=(ans*(len-1))%mod;
                }
                len=1;
                ls=s[i]-'0';
            }
        }
        cout<<lens<<' '<<hw[suml]*ans%mod<<endl;
        //vector<int>
    }
    return 0;
} 