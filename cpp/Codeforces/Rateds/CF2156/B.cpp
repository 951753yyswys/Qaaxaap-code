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
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        vector<int> qs(q);
        for(auto &tmp:qs) cin>>tmp;
        bool flaga=1;
        for(char c:s) 
        {
            if(c=='B') 
            {
                flaga=false;
                break;
            }
        }
        if(flaga) 
        {
            for(int a:qs) 
                cout<<a<<" ";
            cout<<endl;
        } 
        else 
        {
            for(int a:qs) 
            {
                int ans=0;
                int pos=0;
                int now=a;
                while(now>0) 
                {
                    if(s[pos]=='A') 
                        now--;
                    else 
                        now=now/2;
                    ans++;
                    pos=(pos+1)%n;
                }
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}