#include<bits/stdc++.h>
using namespace std;
namespace Qaaxaap
{
    inline void work1()
    {
        int n,m,hd=0;
        cin>>n>>m;
        vector<int> cl(m);
        for(int i=1;i<=n;i++) 
        {
            int a,b,c;
            cin>>a>>b>>c;
            cl[a-1]+=b;
            hd+=c;
        }
        sort(cl.begin(),cl.end());
        int ans=0,sum=0;
        for(int i=0;i<m;i++)
        {

        }
    }
    inline void work()
    {
        
    }
}
int main()
{
    ios::sync_with_stdio(0);
    return Qaaxaap::work(),0;
}