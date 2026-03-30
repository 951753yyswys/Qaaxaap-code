#include<bits/stdc++.h>
using namespace std;
#define int long long
int mp[51][51];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        for(int i=20;i<=40;i++) for(int j=20;j<=40;j++) mp[i][j]=0;
        string yk;
        cin>>yk;
        int cnt=1;
        int x=0,y=0;
        for(int tt=1;tt<=100;tt++)
        {
            for(int i=0;i<n;i++) 
            {
                if(yk[i]=='N') y++;
                if(yk[i]=='E') x++;
                if(yk[i]=='S') y--;
                if(yk[i]=='W') x--;
                if(x+30>40||x+30<20) continue;
                if(y+30>40||y+30<20) continue;
                mp[x+30][y+30]=1;
            }
        }
        if(mp[a+30][b+30]) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
} 