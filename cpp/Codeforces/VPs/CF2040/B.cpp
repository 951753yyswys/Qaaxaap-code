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
        if(n==1) cout<<1<<endl;
        else
        {
            int ans=2,ls=4;
            while(ls<n)
            {
                ans++;
                ls*=2;
                ls+=2;
            }
            cout<<ans<<endl;    
        }
        //vector<int>
    }
    return 0;
} 