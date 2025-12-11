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
        int x,y;
        cin>>x>>y;
        if(y==1) 
        {
            cout<<-1<<endl;
            continue;
        }
        if(x<y) cout<<2<<endl;
        else if(x-1>y) cout<<3<<endl;
        else cout<<-1<<endl;
        //vector<int>
    }
    return 0;
} 