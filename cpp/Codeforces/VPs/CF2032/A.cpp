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
        int sa=0,sb=0;
        for(int i=1;i<=2*n;i++) 
        {
            int l;
            cin>>l;
            if(l) sa++;
            else sb++;
        }
        cout<<sa%2<<' '<<min(sb,sa)<<endl;
    }
    return 0;
} 