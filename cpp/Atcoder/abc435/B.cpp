#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    void work()
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(auto &tmp:a) cin>>tmp;
        int ans=0;
        for(int i=0;i<n;i++) 
        {
            for(int j=i;j<n;j++)
            {
                int sum=0;
                for(int k=i;k<=j;k++) sum+=a[k];
                bool flag=1;
                for(int k=i;k<=j;k++) flag&=(sum%a[k]!=0);
                ans+=flag;
            }
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