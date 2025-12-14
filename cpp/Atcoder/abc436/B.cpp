#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    int mp[1010][1010];
    void work()
    {
        memset(mp,-1,sizeof(mp));
        int n;
        cin>>n;
        mp[0][(n-1)/2]=1;
        int r=0,c=(n-1)/2,k=1;
        for(int i=1;i<=n*n-1;i++)
        {
            if(mp[(r-1+n)%n][(c+1)%n]==-1) mp[(r-1+n)%n][(c+1)%n]=k+1,r=(r-1+n)%n,c=(c+1)%n;
            else mp[(r+1)%n][c]=k+1,r=(r+1)%n;
            k++;
        }
        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<n;j++)
            {
                cout<<mp[i][j]<<' ';
            }
            cout<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    return Qaaxaap::work(),0;
} 