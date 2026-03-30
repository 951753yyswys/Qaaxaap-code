#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        int fir=0x7fffffff,ls=0,dw=0,cnt=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==0) fir=min(fir,i),ls=max(ls,i);
            else cnt++;
        }
        for(int i=0;i<n-1;i++)
        {
            if(a[i]!=0&&a[i+1]==0) dw=max(1ll,dw);
            if(dw==1&&a[i]==0&&a[i+1]!=0) dw=2;
        }
        if(cnt==0) cout<<0<<endl;
        else if(dw==2) cout<<2<<endl;
        else cout<<1<<endl;

    }
    return 0;
} 