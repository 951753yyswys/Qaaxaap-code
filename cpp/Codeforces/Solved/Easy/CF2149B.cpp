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
        sort(a.begin(),a.end());
        int ans=0;
        for(int i=0;i<n-1;i+=2)
            ans=max(ans,abs(a[i]-a[i+1]));
        cout<<ans<<endl;
    }
    return 0;
} 