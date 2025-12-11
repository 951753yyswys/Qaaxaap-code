#include<bits/stdc++.h>
using namespace std;
//using namespace IO;
#define int long long
namespace Qaaxaap
{
    const int p=998244353,N=5e5+5;
    int dp[5];
    void work()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int n;
            cin>>n;
            dp[0]=1,dp[1]=dp[2]=0;
            for(int i=1;i<=n;i++)
            {
                vector<int> ldp(5);
                ldp[0]=dp[1]+dp[0]+dp[2];
                ldp[1]=dp[0];
                ldp[2]=dp[1];
                dp[0]=ldp[0];
                dp[1]=ldp[1];
                dp[2]=ldp[2];
                //cout<<i<<endl<<dp[0]<<' '<<dp[1]<<' '<<dp[2]<<endl;
            }
            cout<<dp[0]+dp[1]+dp[2]<<endl;    
        }
        
    }
};
signed main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}