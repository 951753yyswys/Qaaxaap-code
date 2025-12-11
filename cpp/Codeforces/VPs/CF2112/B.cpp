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
        for(int i=0;i<n;i++) cin>>a[i];
        int flag=0;
        for(int i=1;i<n;i++) if(abs(a[i]-a[i-1])<=1) flag=1;
        if(flag) cout<<0<<endl;
        else
        {
            for(int i=1;i<n-1;i++) if(a[i]>a[i-1]&&a[i]>a[i+1]) flag=1;
            for(int i=1;i<n-1;i++) if(a[i]<a[i-1]&&a[i]<a[i+1]) flag=1;
            if(flag) cout<<1<<endl;
            else cout<<-1<<endl;
        }
    }
    return 0;
} 