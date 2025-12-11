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
        int x,d,n,rating;
        cin>>rating>>x>>d>>n;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            char ll;
            cin>>ll;
            int tmp=ll-'0';
            if(tmp==1) 
                rating=max(0ll,rating-d),ans++;
            else if(rating<x) 
                    rating=max(0ll,rating-d),ans++;    
        }
        cout<<ans<<endl;
    }
    return 0;
} 