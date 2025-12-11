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
        int mxw=0,mxh=0;
        for(int i=1;i<=n;i++)
        {
            int w,h;
            cin>>w>>h;
            mxw=max(mxw,w);
            mxh=max(mxh,h);
        }
        cout<<2*mxw+2*mxh<<endl;
        //vector<int>
    }
    return 0;
} 