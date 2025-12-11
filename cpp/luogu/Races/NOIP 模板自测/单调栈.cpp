#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    void work()
    {
        int n;
        cin>>n;
        vector<int> a(n),f(n,-1);
        for(auto &tmp:a) cin>>tmp;
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&st.top().second<=a[i]) st.pop();
            if(!st.empty()) f[i]=st.top().first;
            st.push({i,a[i]});
        }
        for(auto tmp:f) cout<<tmp+1<<' ';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}