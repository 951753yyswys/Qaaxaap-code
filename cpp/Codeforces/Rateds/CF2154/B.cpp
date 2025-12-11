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
        vector<int> a(n+2);
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=0,mx=-0x7ffffff;
        a[0]=-0x7fffffff;
        for(int i=1;i<=n;i++)
        {
            mx=max(mx,a[i]);
            if(i%2==0) a[i]=mx;
        }
        a[0]=a[2];
        a[n+1]=0x7fffffff;
        for(int i=1;i<=n;i++)
        {
            if(i%2==1)
            {
                if(a[i]<a[i-1]) continue;
                ans+=a[i]-a[i-1];
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
} 