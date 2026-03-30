#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    pair<int,int> dfs(int a,int b,int c,int d)
    {
        if(a<=b&&c>d) return {1,1};
        pair<int,int> ans=dfs(d%c,c,b-a*(d/c),a);
        swap(ans.first,ans.second);
        ans.second+=ans.first*(d/c);
        return ans;
    }
    int pow10[17];
    void work()
    {
        pow10[0]=1;
        for(int i=1;i<=16;i++) pow10[i]=pow10[i-1]*10ll;
        int n;
        while(cin>>n)
        {
            int a,b,c,d;
            int e=0;
            char ll=' ';
            while(cin>>ll&&ll!='.') e*=10,e+=ll-'0';
            for(int i=1;i<=n;i++) cin>>ll,e*=10,e+=ll-'0';
            if(e<=0)
            {
                cout<<1<<endl;
                continue;
            } 
            //cout<<' '<<e<<end9l;
            a=10*e-5ll;
            b=pow10[n+1];
            c=10*e+5ll;
            d=pow10[n+1];
            pair<int,int> ans=dfs(a,b,c,d);
            cout<<min(ans.second,b/__gcd(a,b))<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}