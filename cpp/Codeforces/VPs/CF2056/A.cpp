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
        int n,m;
        cin>>n>>m;
        int sx=0,sy=0;
        for(int i=1;i<=n;i++)
        {
            int x,y;
            cin>>x>>y;
            if(i==1) continue;
            sx+=x;
            sy+=y;
        }
        sx+=m;
        sy+=m;
        cout<<sx*2+sy*2<<endl;
    }
    return 0;
} 