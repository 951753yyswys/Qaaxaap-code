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
        int n,k,ans=1;
        cin>>n>>k;
        vector<int> a(n),cnt(4*n+1),snt(4*n+1);
        for(auto &tmp:a) cin>>tmp,cnt[tmp]++;
        for(int i=1;i<=4*n;i++) snt[i]=snt[i-1]+cnt[i];
        for(int i=n;i>=1;i--)
        {
            int yk=snt[4*i-1]-cnt[i]-cnt[i*2]-cnt[i*3];
            if(yk<=k) 
            {
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
} 