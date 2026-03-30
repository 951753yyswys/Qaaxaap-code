#include<bits/stdc++.h>
using namespace std;
#define int long long
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
        vector<int> ans(n);
        int gr=-2;
        for(int i=0;i<n-n%6;i++) 
        {
            int tl=i%6;
            if(tl==0) gr+=3;
            if(tl==0||tl==1||tl==4) ans[i]=gr;
            if(tl==2||tl==5) ans[i]=gr+1;
            if(tl==3) ans[i]=gr+2;
        }
        if(n%6==1) ans[n-1]=gr+2;
        if(n%6==2) ans[n-2]=gr+3,ans[n-1]=gr+2;
        if(n%6==3) ans[n-3]=gr+4,ans[n-2]=gr+3,ans[n-1]=gr+2;
        if(n%6==4) ans[n-4]=gr+5,ans[n-3]=gr+4,ans[n-2]=gr+3,ans[n-1]=gr+2;
        if(n%6==5) ans[n-5]=gr+6,ans[n-4]=gr+5,ans[n-3]=gr+4,ans[n-2]=gr+3,ans[n-1]=gr+2;
        for(int tmp:ans) cout<<tmp<<' ';
        cout<<endl;
    }
    return 0;
} 