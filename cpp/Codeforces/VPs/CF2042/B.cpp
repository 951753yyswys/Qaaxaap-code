#include<bits/stdc++.h>
#define sor(i,l,r) for(int i=l;i<=r;i++)
#define int long long
using namespace std;
namespace Revitalize
{
    const int N=5e5;
    int T,n,a[N],b[N];
    inline void work(){
        cin>>T;
        while(T--)
        {
            cin>>n;
            sor(i,1,n) cin>>a[i],b[i]=a[i];
            int cnt=0;
            int num=0;
            vector<int> S(n+1);
            sor(j,1,n)
            {
                if(a[j]>0) S[a[j]]++;
            }
            sor(i,1,n) if(S[i]==1) num++;
            vector<bool> vis(n+1);
            sor(i,1,n)
            {
                vector<int> s(n+1,0);
                sor(j,1,n)
                {
                    if(a[j]>0) s[a[j]]++;
                }
                
                int mn=10000000000,mna=0;
                sor(j,1,n)
                {
                    if(s[a[j]]&&s[a[j]]<mn) mn=s[a[j]],mna=j;
                }
                if(i&1){
                    if(!vis[a[mna]]) vis[a[mna]]=1,cnt++;
                    a[mna]=-1;
                }
                else a[mna]=-2;
                //cout<<cnt<<" ";
                cout<<"cnt:"<<cnt<<'\n';
                cout<<"mn,mna:"<<mn<<' '<<mna<<'\n';
            }
            cout<<cnt+(num+1)/2<<"\n";
            
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    return Revitalize::work(),0;
}