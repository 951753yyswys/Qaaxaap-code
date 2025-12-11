#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,n;
        cin>>a>>b>>n;
        vector<int> x(n);
        for(int i=0;i<n;i++) cin>>x[i];
        int ans=b;
        for(int i=0;i<n;i++)
        {
            ans+=min(x[i],a-1);
        }
        cout<<ans<<endl;
    }
}