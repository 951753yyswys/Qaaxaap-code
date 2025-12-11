#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    int cnt[2002][2002],cl[2002][2002];
    void work()
    {
        int n;
        cin>>n;
        const int mxx=2001; 
        for(int i=1;i<=n;i++) 
        {
            int u,d,l,r;
            cin>>u>>d>>l>>r;
            cnt[u][l]+=1;
            cnt[u][r+1]-=1;
            cnt[d+1][l]-=1;
            cnt[d+1][r+1]+=1;
            cl[u][l]+=i;
            cl[u][r+1]-=i;
            cl[d+1][l]-=i;
            cl[d+1][r+1]+=i;
        }
        for(int r=0;r<=mxx;r++) for(int c=1;c<=mxx;c++) 
        {
            cnt[r][c]+=cnt[r][c-1];
            cl[r][c]+=cl[r][c-1];
        }
        for(int c=0;c<=mxx;c++) for(int r=1;r<=mxx;r++) 
        {
            cnt[r][c]+=cnt[r-1][c];
            cl[r][c]+=cl[r-1][c];
        }
        int ze=0;
        vector<int> lx(n+1);
        for(int r=1;r<=2000;r++) 
        {
            for(int c=1;c<=2000;c++) 
            {
                if(cnt[r][c]==0) ze++;
                else if(cnt[r][c]==1) lx[cl[r][c]]++;
            }
        }
        for(int k=1;k<=n;k++) cout<<ze+lx[k]<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}