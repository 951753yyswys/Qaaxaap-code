#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    void work()
    {
        int n;
        cin>>n;
        vector<int> a(n+1);
        int cnt=0,mx=1;
        for(int i=1;i<=n;i++) 
        {
            cin>>a[i];
            if(i<=mx) 
            {
                cnt++;
                mx=max(mx,a[i]+i-1);
            }
        }
        cout<<cnt;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return Qaaxaap::work(),0;
}