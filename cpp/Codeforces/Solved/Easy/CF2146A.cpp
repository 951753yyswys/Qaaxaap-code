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
        int n,num=0;
        cin>>n;
        vector<int> a(n),cnt(n),sor;
        for(auto &tmp:a) cin>>tmp,cnt[tmp-1]++;
        for(auto tmp:cnt)
        {
            if(tmp==0) continue;
            sor.push_back(tmp);
        }
        sort(sor.rbegin(),sor.rend());
        int ans=0;
        for(auto tmp:sor)
        {
            num++;
            ans=max(ans,num*tmp);
        }
        cout<<ans<<endl;
    }
    return 0;
} 