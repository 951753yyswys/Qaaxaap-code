#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    void work()
    {
        int n,w;
        cin>>n>>w;
        vector<int> a(n);
        for(auto &tmp:a) cin>>tmp;
        sort(a.begin(),a.end());
        int ans=0;
        for(auto tmp:a)
        {
            if(w>=tmp) ans++,w-=tmp;
            else break;
        }
        cout<<ans;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return Qaaxaap::work(),0;
} 