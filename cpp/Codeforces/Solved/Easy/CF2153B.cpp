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
        int x,y,z;
        cin>>x>>y>>z;
        if((x&y)==(y&z)&&(x&z)==(y&z)&&(x&y)==(x&z)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
} 