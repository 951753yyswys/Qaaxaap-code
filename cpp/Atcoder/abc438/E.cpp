#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
	const int mx=30;
	int up[mx][200000+5],sumv[mx][200000+5];
    void work()
    {
        int n,q;
        cin>>n>>q;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int v=1;v<=n;v++)
        {
            up[0][v]=a[v];
            sumv[0][v]=v;
        }
        for(int k=1;k<mx;k++) for(int v=1;v<=n;v++)
        {
			int mid=up[k-1][v];
            up[k][v]=up[k-1][mid];
            sumv[k][v]=sumv[k-1][v]+sumv[k-1][mid];
        }
        while(q--)
        {
            int t,b;
            cin>>t>>b;
            int ans=0,cur=b;
            for(int k=0;k<mx;k++) if((t>>k)&1)
            {
                ans+=sumv[k][cur];
                cur=up[k][cur];
            }
            cout<<ans<<endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Qaaxaap::work(), 0;
}

