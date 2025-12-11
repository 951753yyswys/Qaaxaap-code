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
        vector<char> a(n),b(n);
        for(char &tmp:a) cin>>tmp;
        for(char &tmp:b) cin>>tmp;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int flag=1;
        for(int i=0;i<n;i++) if(a[i]!=b[i]) flag=0;
        if(flag) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
} 