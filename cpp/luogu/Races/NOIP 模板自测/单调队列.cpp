#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    void work()
    {
        int n,k;
        cin>>n>>k;
        vector<int> a(n+1);
        deque<pair<int,int>> q;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<k;i++)
        {
            while(!q.empty()&&q.front().second>=a[i]) q.pop_front();
            q.push_front({i,a[i]});
        }
        for(int i=k;i<=n;i++)
        {
            while(!q.empty()&&q.front().second>=a[i]) q.pop_front();
            q.push_front({i,a[i]});
            int l=i-k+1;
            while(!q.empty()&&q.back().first<l) q.pop_back();
            cout<<q.back().second<<' ';
        }
        cout<<endl;
        q.clear();
        for(int i=1;i<k;i++)
        {
            while(!q.empty()&&q.front().second<=a[i]) q.pop_front();
            q.push_front({i,a[i]});
        }
        for(int i=k;i<=n;i++)
        {
            while(!q.empty()&&q.front().second<=a[i]) q.pop_front();
            q.push_front({i,a[i]});
            int l=i-k+1;
            while(!q.empty()&&q.back().first<l) q.pop_back();
            cout<<q.back().second<<' ';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}