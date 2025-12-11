#include<bits/stdc++.h>
#define sor(i,l,r) for(int i=l;i<=r;i++)
#define int long long
using namespace std;
namespace Revitalize
{
    const int N=5e5;
    int T,n,a,b;
    inline void work(){
        cin>>T;
        while(T--)
        {
            cin>>n>>a>>b;
            if(a==0)
            {
                if(b==n-1||b==n-2) cout<<n-1<<"\n";
                else if(b>=n) cout<<n<<"\n";
                else cout<<-1<<"\n";
                continue;
            }
            if(b>=n)
            {
                cout<<n<<"\n";
                continue;
            }
            cout<<n-max(0ll,(1+(n-b-1)/a))<<"\n";
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    return Revitalize::work(),0;
}