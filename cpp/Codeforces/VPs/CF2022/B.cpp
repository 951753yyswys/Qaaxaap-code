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
        int n,x;
        cin>>n>>x;
        vector<int> a(n);
        for(auto &tmp:a) cin>>tmp;
        sort(a.rbegin(),a.rend());
        int ans=0;
        int i=0;
        while(i<n)
        {
            if(a[i]==0) i++;
            ans+=a[i];
            int low=x;
            while(low&&++i<n) a[i]-=low,a[i]=max(0ll,a[i]),low-=a[i],low=max(0ll,low); 
        }
        cout<<ans<<endl;
    }
    return 0;
} 