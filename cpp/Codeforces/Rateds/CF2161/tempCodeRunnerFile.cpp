#include<bits/stdc++.h>
#define int long long 
using namespace std;
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(auto &tmp:a) cin>>tmp;
        vector<vector<int>> pos(n+1);
        for(int i=0;i<n;i++)
            pos[a[i]].push_back(i);
        vector<int> c(n+1,0),F(n+1,n+10),L(n+1,-1);
        for(int x=1;x<=n;x++) 
        {
            if(!pos[x].empty()) 
            {
                c[x]=pos[x].size();
                F[x]=pos[x][0];
                L[x]=pos[x].back();
            }
        }
        vector<int> dp0(n+2,0),dp1(n+2,0),lst1(n+2,-1),dp01(n+2,0);
        dp01[n+1]=0;
        dp01[n+2]=0;
        dp0[n+1]=0;
        dp1[n+1]=0;
        lst1[n+1]=-1;
        for(int x=n;x>=1;x--) 
            if(c[x]==0) 
            {
                dp0[x]=dp01[x+1];
                dp1[x]=0;
                lst1[x]=-1;
                dp01[x]=max(dp0[x],dp1[x]);
            } 
            else 
            {
                int lsa=c[x]+dp01[x+2];
                int lsb=-1;
                if(dp1[x+1]>0) 
                {
                    if(lst1[x+1]<F[x])
                        lsb=c[x]+dp1[x+1];
                    else 
                    {
                        auto it=upper_bound(pos[x].begin(),pos[x].end(),lst1[x+1]);
                        int k=pos[x].end()-it;
                        lsb=dp1[x+1]+k;
                    }
                }
                if(lsb==-1)
                    dp1[x]=lsa;
                else 
                    dp1[x]=max(lsa,lsb);
                lst1[x]=L[x];
                dp0[x]=dp01[x+1];
                dp01[x]=max(dp0[x],dp1[x]);
            }
        cout<<n-dp01[1]<<endl;
    }
    
    return 0;
}