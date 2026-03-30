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
        vector<int> a(n),cnt(101,0);
        for(auto &tmp:a) cin>>tmp,cnt[tmp]=1;
        int sum=0;
        for(auto tmp:cnt) sum+=tmp;
        cout<<sum*2-1<<endl;
    }
    return 0;
} 