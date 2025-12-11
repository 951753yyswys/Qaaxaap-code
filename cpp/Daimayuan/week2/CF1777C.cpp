#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    void work()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int n,m;
            cin>>n>>m;
            vector<int> a(n),mul(m+1);
            for(auto &tmp:a) cin>>tmp;
            sort(a.begin(),a.end());
            int ans=0x7fffffff,r=-1,sum=0;
            for(int l=0;l<n&&r<n;l++)
            {
                if(l!=0)
                {
                    for(int i=1;i<=sqrt(a[l-1])&&i<=m;i++) if(a[l-1]%i==0)
                    {
                        mul[i]--;
                        if(mul[i]==0) sum--;
                        if(a[l-1]/i>m) continue;
                        mul[a[l-1]/i]--;
                        if(mul[a[l-1]/i]==0) sum--;
                    }
                }
                while(sum<m&&r<n-1)
                {
                    r++;
                    for(int i=1;i<=sqrt(a[r])&&i<=m;i++) if(a[r]%i==0)
                    {
                        mul[i]++;
                        if(mul[i]==1) sum++;
                        if(a[r]/i>m) continue;
                        mul[a[r]/i]++;
                        if(mul[a[r]/i]==1) sum++;
                    }
                    //cout<<'r'<<r<<endl;
                    //for(auto tmp:mul) cout<<tmp<<' ';
                    //cout<<endl;
                }
                if(sum==m) ans=min(ans,a[r]-a[l]);//,cout<<l<<' '<<r<<endl;
            }
            if(ans==0x7fffffff) ans=-1;
            cout<<ans<<' ';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}