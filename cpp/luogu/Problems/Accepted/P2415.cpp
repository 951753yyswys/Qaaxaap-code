#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
signed main()
{
    int sum=0,n=0,l;
    while(cin>>l)
    {
        n++;
        sum+=l;
    }
    cout<<(sum<<n-1);
    return 0;
}