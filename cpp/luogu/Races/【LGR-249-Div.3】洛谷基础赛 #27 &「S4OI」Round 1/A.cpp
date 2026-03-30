#include<bits/stdc++.h>
using namespace std;
namespace Qaaxaap
{
    inline void work()
    {
        int n,m,k,l,r;
        cin>>n>>m>>k>>l>>r;
        vector<int> a(n);
        for(int i=1;i<=k;i++)
        {
            int x,y,v;
            cin>>x>>y>>v;
            if(v<=l) v=100;
            else if(v>=r) v=0;
            a[x-1]+=v;
        }
        for(auto tmp:a) cout<<tmp<<' ';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    return Qaaxaap::work(),0;
}