
#include<bits/stdc++.h>
#define int long long
using namespace std;
int win[10101],los[10101];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int wt=n,lt=0,ans=0;
        for(int i=1;i<=n;i++) win[i]=i,los[i]=0;
        while(wt>1||lt>1)
        {
            for(int i=1;i<=lt;i++) if(i%2==0) lt--,ans++; 
            for(int i=1;i<=lt;i++) los[i]=los[i*2-1];
            for(int i=1;i<=wt;i++) if(i%2==0) wt--,ans++,los[++lt]=win[i];
            for(int i=1;i<=wt;i++) win[i]=win[2*i-1];
            //cout<<"wt:"<<wt<<" lt:"<<lt<<endl;
        }
        cout<<ans+1<<endl;
    }
    return 0;
}