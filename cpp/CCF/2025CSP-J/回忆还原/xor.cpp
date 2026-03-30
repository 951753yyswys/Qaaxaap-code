#include<bits/stdc++.h>
using namespace std;
#define int long long
int lst[2020202],sum[2020202];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) 
    {
        int tmp;
        cin>>tmp;
        sum[i]=sum[i-1]^tmp;
    }
    int ls=0,ans=0;
    lst[0]=0;
    for(int i=1;i<=2020200;i++) lst[i]=-2020202;
    for(int i=1;i<=n;i++)
    {
        int zhq=lst[sum[i]^k];
        if(zhq>=ls) ans++,ls=i;
        lst[sum[i]]=i;
    }
    cout<<ans;
    return 0;
} 