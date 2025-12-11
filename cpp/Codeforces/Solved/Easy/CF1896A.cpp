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
        for(auto &tmp:a) cin>>tmp;
        int flag=a[0];
        if(flag==1) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
} 