#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    void work()
    {
        int T;
        cin>>T;
        while(T--)
        {
            int n;
            cin>>n;
            vector<int> b(n);
            int sum=0,cnt=0;
            for(auto &tmp:b) 
            {
                cin>>tmp;
                if(tmp==0) continue;
                cnt++;
                sum+=tmp;
            }
            //sort(b.begin(),b.end());
            sum-=n-1;
            cout<<min(sum,cnt)<<endl;
        }
        
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}