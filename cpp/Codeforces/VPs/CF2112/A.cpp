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
        int a,x,y;
        cin>>a>>x>>y;
        if(x<y) swap(x,y);
        int mid=x+y>>1;
        //if(((x-y)%2==1&&(a*2==(x+y-1)||a*2==(x+y+1)))||(mid==a&&(x-y)%2==0)) cout<<"no\n";
        // if((x-y)%2==0)
        // {
        //     if(a==mid) cout<<"no\n";
        //     else cout<<"yes\n";
        // }
        // else 
        // {
        //     if(a==(x+y+1)/2) cout<<"no\n";
        //     else if(a==(x+y-1)/2) cout<<"no\n";
        //     else cout<<"yes\n";
        // }
        int len=(x-y+1)>>1;
        if(a<=x&&a>=y) cout<<"No\n";
        else if(a>x) 
        {
            cout<<"Yes\n";
        }
        else 
        {
            cout<<"Yes\n";
        }
        //vector<int>
    }
    return 0;
} 