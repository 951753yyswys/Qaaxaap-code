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
        int sum0=0,sum1=0,sum2=0;
        vector<int> a(n);
        for(auto &tmp:a) 
        {
            cin>>tmp;
            if(tmp==0) sum0++;
            if(tmp==1) sum1++;
            if(tmp==-1) sum2++;
        }
        cout<<sum0+(sum2%2)*2<<endl;
    }
    return 0;
} 