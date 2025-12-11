#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    void work()
    {
        int x,y,z;
        cin>>x>>y>>z;
        bool flag=0;
        while(x/y>=z)
        {
            if(x/y*y==x) 
            {
                flag=1;
                break;
            }
            x++;
            y++;
        }
        if(flag) cout<<"Yes";
        else cout<<"No";
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}