#include<bits/stdc++.h>
#include<windows.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    bool iq(int x)
    {
        return ((int)sqrt(x))*((int)sqrt(x))==x;
    }
    void work()
    {
        int n,flag=0;
        cin>>n;
        cout<<iq(25);
        while(1)
        {
            if(flag) break;
            n++;
            for(int a=1;a*a<n;a++)
            {
                int b=n-a*a;
                if(b==0) continue;
                if(!iq(b)) continue;
                int c=n-2023;
                if(iq(c))
                {
                    cout<<"n:"<<n<<endl;
                    cout<<"a:"<<a<<endl;
                    cout<<"b:"<<sqrt(b)<<endl;
                    cout<<"c:"<<sqrt(c)<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag) break;
            if(clock()%10==0) cout<<'\r'<<n<<" NO";
        }
    }
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}