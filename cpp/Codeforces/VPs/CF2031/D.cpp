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
        vector<int> a(n),ans(n),mi(n),mx(n);
        for(auto &tmp:a) cin>>tmp;
        mi[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)
            mi[i]=min(a[i],mi[i+1]);
        mx[0]=a[0];
        for(int i=1;i<n;i++)
            mx[i]=max(a[i],mx[i-1]);
        ans[n-1]=mx[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(mx[i]>mi[i+1]) 
                ans[i]=ans[i+1];
            else
                ans[i]=mx[i];
        }
        for(auto tmp:ans) cout<<tmp<<' ';
        cout<<endl;
    }
    return 0;
} 