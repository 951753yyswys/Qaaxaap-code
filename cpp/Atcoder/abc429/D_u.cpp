#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<stdlib.h>
#include<stdio.h>
#include<unordered_map>
#define int long long
using namespace std;

const int N=5e5+5;

int n,m,c,cnt,ans;
int a[N],b[N],f[N<<1];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    cnt=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(b+1,b+cnt+1,a[i])-b;
        f[a[i]]++;
        f[a[i]+cnt]++;
    }
    for(int i=1;i<=cnt*2;i++)
        f[i]+=f[i-1];
    for(int i=1;i<=cnt;i++)
    {
        int tem=f[lower_bound(f+1,f+cnt*2+1,f[i-1]+c)-f]-f[i-1];
        if(i==1)
            ans+=(b[i]+m-b[cnt])*tem;
        else
            ans+=(b[i]-b[i-1])*tem;
        // cout<<b[i]<<" "<<b[t]<<" "<<f[i]<<" "<<f[lower_bound(f+1,f+cnt*2+1,f[i]+c)-f]<<endl;
        // ans+=((b[i]-b[t]+m-1)%m+1)*tem;
    }
    cout<<ans<<endl;
    return 0;
}