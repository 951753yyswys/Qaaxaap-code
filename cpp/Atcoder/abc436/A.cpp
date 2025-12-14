#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    void work()
    {
        int n;
        string s;
        cin>>n>>s;
        for(int i=1;i<=n-s.size();i++) cout<<'o';
        cout<<s;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return Qaaxaap::work(),0;
} 