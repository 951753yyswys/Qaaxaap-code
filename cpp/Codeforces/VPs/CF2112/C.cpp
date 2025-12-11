#include<bits/stdc++.h>
#define len (tail-head+1)
using namespace std;
#define int long long
int a[1010101];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,mx=0;
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i],mx=max(mx,a[i]);
        sort(a,a+n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++) 
            {
                int lit=upper_bound(a,a+n,mx-a[i]-a[j])-a;
                if(a[lit]<=mx-a[i]-a[j]) lit=n;
                lit=max(lit,j+1);
                ans+=n-lit;
                cout<<"i j lit "<<i<<' '<<j<<' '<<lit<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
} 