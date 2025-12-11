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
        int ans=0x7fffffffffff,r=1;
        if(a[0]+a[1]>a[n-1]) 
        {
            cout<<0<<endl;
            continue;
        }
        for(int l=0;l<n;l++)
        {
            if(r==n) break; 
            while(l+1>r) r++;
            while(a[l]+a[l+1]>a[r]) 
            {
                r++;
                if(r==n) 
                {
                    ans=min(ans,n-r+l);
                    break;
                }
            }
            if(r>n) break;
            ans=min(ans,n-r+l);
        }
        cout<<ans<<endl;
    }
    return 0;
} 