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
        vector<int> h(n);
        for(auto &tmp:h) cin>>tmp;
        int ans=0,ans1=0;
        for(auto hw:h)
        {
            ans1=0;
            for(auto tmp:h)
            {
                if(hw==tmp) ans1++;
            }
            ans=max(ans,ans1);
        }
        cout<<n-ans<<endl;
    }
    return 0;
} 