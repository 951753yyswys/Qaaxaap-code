#include<bits/stdc++.h>
using namespace std;
namespace Qaaxaap
{
    const int N=5e6;
    vector<int> pri;
    bool npi[N];
    void pre(int n) 
    {
        for(int i=2;i<=n;i++) 
        {
            if(!npi[i]) 
            pri.push_back(i);
            for(int pj:pri) 
            {
                if(i*pj>n) break;
                npi[i*pj]=1;
                if(i%pj==0) break;
            }
        }
    }
    inline void work()
    {
        pre(1919810);
        int n,m;
        cin>>n>>m;
        if(m%2==0) m++;
        else m+=2;
        for(int i=n;i>=1;i--) cout<<(m-=2)<<' ';
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return Qaaxaap::work(),0;
}