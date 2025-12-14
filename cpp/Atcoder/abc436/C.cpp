
#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    void work()
    {
        int n,m;
        cin>>n>>m;
        int ans=0;
        set<pair<int,int>> alm;
        while(m--)
        {
            int r,c;
            cin>>r>>c;
            bool flag=1;
            for(int i=0;i<2;i++) for(int j=0;j<2;j++)
            {
                if(alm.count({r+i,c+j})) flag=0;
            }
            if(flag==0) continue;
            ans++;
            for(int i=0;i<2;i++) for(int j=0;j<2;j++) alm.insert({r+i,c+j}); 
        }
        cout<<ans<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return Qaaxaap::work(),0;
} 