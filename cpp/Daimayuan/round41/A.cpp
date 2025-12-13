#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    void work()
    {
        int n,x,y,k;
        cin>>n>>x>>y>>k;
        //k+=100*n;
        for(int i=x;i<k;i++) y++;
        cout<<(y-1)%n+1;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return Qaaxaap::work(),0;
} 