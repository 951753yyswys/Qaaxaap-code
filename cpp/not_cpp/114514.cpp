#include<bits/stdc++.h>
#define sor(i,l,r) for(int i=l;i<=r;i++)
#define int long long
        int vis[1010];
using namespace std;
namespace Revitalize
{
    const int N=5e5;
    inline void work(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=2*n;i++) vis[i]=0;
        vector<int> ans(2*n);
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) 
        {
            int l;
            cin>>l;
            ans[i+j-1]=l,vis[l]=1;
        }
        for(int i=1;i<=2*n;i++) 
        {
            if(!vis[i])
            {
                ans[0]=i;
                break;
            }
        }
        for(auto tmp:ans) cout<<tmp<<' ';
        cout<<endl;
    }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    return Revitalize::work(),0;
}