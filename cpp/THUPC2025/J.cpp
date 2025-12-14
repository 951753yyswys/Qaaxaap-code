#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
namespace Qaaxaap
{
    bool cn3(int m) 
    {
        int k=__builtin_ctzll(m);
        if(k&1ull) return 0; 
        int x=m>>k;
        if((x&1)==0) return 0;
        return (x&(x+1ull))==0;
    }
    void work()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int n,m;
            cin>>n>>m;
            if(n%2ull==0ull) 
            {
                cout<<"NO"<<endl;
                continue;
            }
            if(n==1)
            {
                if((1ull<<__builtin_ctzll(m))==(m)&&(__builtin_ctzll(m)%2ull==0ull)) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
                continue;
            }
            if(n==3)
            {
                if(cn3(m)) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
                continue;
            }
            cout<<"YES"<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return Qaaxaap::work(),0;
} 