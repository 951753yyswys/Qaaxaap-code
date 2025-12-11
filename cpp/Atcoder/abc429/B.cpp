#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    int sum=0;
    vector<int> a(n);
    for(auto &tmp:a) cin>>tmp,sum+=tmp;
    for(auto &tmp:a)
    {
        if(sum-tmp==m) 
        {
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
} 