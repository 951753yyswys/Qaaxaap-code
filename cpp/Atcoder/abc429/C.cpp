#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    vector<int> a(n),cnt(n+1);
    for(auto &tmp:a) cin>>tmp,cnt[tmp]++;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]<=1) continue;
        ans+=(n-cnt[i])*(cnt[i]-1)*cnt[i]/2;
    }
    cout<<ans;
    return 0;
} 