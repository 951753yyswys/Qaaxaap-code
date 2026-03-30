#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[101010],n,mi=0;
bool check(int x)
{
    vector<int> mix(n+1,0),mxx(n+1,0);
    mix[1]=mxx[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        mxx[i]=min(a[i],a[1]-mix[i-1]);
        mix[i]=max(0ll,a[i]-(x-(a[1]+a[i-1]-mxx[i-1])));
    }
    if(mix[n]) 
        return 0;
    return 1;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) 
        cin>>a[i],mi=max(mi,a[i]+a[i-1]);
    int ans=1e9,l=mi,r=1e6;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(check(mid)) 
            ans=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ans;
    return 0;
} 