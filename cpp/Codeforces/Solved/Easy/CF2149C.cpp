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
        int n,k;
        cin>>n>>k;
        vector<int> a(n),cnt(n+1);
        for(auto &tmp:a) cin>>tmp,cnt[tmp]++;
        int ans=0;
        for(int i=0;i<k;i++) if(!cnt[i]) ans++;
        if(cnt[k]>ans) ans+=cnt[k]-ans;
        cout<<ans<<endl;
    }
    return 0;
} 