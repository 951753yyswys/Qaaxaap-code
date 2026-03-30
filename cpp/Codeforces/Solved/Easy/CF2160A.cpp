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
        int n,flag=1;
        cin>>n;
        vector<int> a(n),cnt(n+1);
        for(auto &tmp:a) cin>>tmp,flag=min(flag,tmp);
        if(flag) 
        {
            cout<<0<<endl;
            continue;
        }
        int mex=0x7ffffffff;
        for(auto tmp:a)
            if(tmp<=n) cnt[tmp]++;
        for(int i=0;i<=n;i++)
        {
            if(cnt[i]) continue;
            mex=min(mex,i);
        }
        cout<<mex<<endl;
    }
    return 0;
} 