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
        string s;
        int n,k;
        cin>>n>>k;
        cin>>s;
        s='#'+s;
        int ans=0,ls=-0x7fffffff;
        for(int i=1;i<=n;i++) 
        {
            if(s[i]=='1') 
            {
                if(ls>=i-k+1) ls=i;
                else ls=i,ans++;
            }
        }
        cout<<ans<<endl;
        //vector<int>
    }
    return 0;
} 