#include<bits/stdc++.h>
#define int __int128
using namespace std;
namespace Liminal
{
    void pri(__int128 x)
    {
        stack<signed> tmp;
        while(x!=0)
        {
            tmp.push(x%10);
            x/=10;
        }
        while(!tmp.empty())
        {
            cout<<tmp.top();
            tmp.pop();
        }
    }
    const long long N=5e5;
    long long T,n,k;
    int p,a,b,q,c,d,m,t;
    bool check(int mid)
    {
        return 1;
    }
    inline void work()
    {
        cin>>T;
        while(T--)
        {
            cin>>p>>a>>b>>q>>c>>d>>m>>t;
            
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    return Liminal::work(),0;
}