#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    void work()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            vector<int> a(n);
            int mx=-1,ans=0;
            for(auto &tmp:a) 
            {
                cin>>tmp;
                if(mx<=tmp) mx=tmp;
                else ans++;
            }
            cout<<ans<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return Qaaxaap::work(),0;
} 