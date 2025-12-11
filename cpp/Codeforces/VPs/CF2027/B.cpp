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
        vector<int> a(n);
        for(auto &tmp:a) cin>>tmp;
        int ans=0x7fffffffff;
        for(int i=0;i<n;i++)
        {   
            int lans=i;
            for(int j=i+1;j<n;j++)
                if(a[j]>a[i]) 
                    lans++;
            ans=min(ans,lans);
        }
        cout<<ans<<endl;
    }
    return 0;
} 