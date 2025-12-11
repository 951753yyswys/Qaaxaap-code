#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    void work()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            int y=n%5;
            for(int i=1;i<=n/5;i++) cout<<'a';
            for(int i=1;i<=n/5+(y>=4);i++) cout<<'e';
            for(int i=1;i<=n/5+(y>=3);i++) cout<<'i'; 
            for(int i=1;i<=n/5+(y>=2);i++) cout<<'o'; 
            for(int i=1;i<=n/5+(y>=1);i++) cout<<'u'; 
            cout<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}