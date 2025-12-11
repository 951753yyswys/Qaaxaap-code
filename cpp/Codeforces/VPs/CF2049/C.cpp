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
        int n,x,y;
        cin>>n>>x>>y;
        vector<int> ans(n);
        if(n%2==0) 
        {
            int ls=1;
            for(int i=x-2;i>=0;i--) ans[i]=ls,ls^=1;
            ls=1;
            for(int i=x;i<n;i++) ans[i]=ls,ls^=1;
            if(ans[y-1]==0) ans[x-1]=2;
            for(auto tmp:ans) cout<<tmp<<' ';
        }
        else
        {
            int ls=1;
            ans[x-1]=2;
            for(int i=x-2;i>=0;i--) ans[i]=ls,ls^=1;
            ls=0;
            for(int i=x;i<n;i++) ans[i]=ls,ls^=1;
            for(auto tmp:ans) cout<<tmp<<' ';
        }
        cout<<endl;
    }
    return 0;
} 