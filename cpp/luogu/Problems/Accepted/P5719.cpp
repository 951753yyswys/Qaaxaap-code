#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    pair<int,int> dfs(int a,int b,int c,int d)
    {
        if(a<b&&c>d) return {1,1};
        pair<int,int> ans=dfs(d%c,c,b-a*(d/c),a);
        swap(ans.first,ans.second);
        ans.second+=ans.first*(d/c);
        return ans;
    }
    void work()
    {
        int a,b,c,d;
        while(cin>>a>>b>>c>>d)
        {
            pair<int,int> ans=dfs(a,b,c,d);
            cout<<ans.first<<"/"<<ans.second<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}