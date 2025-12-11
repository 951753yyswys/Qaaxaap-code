#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>m>>n;
    if(n>m) n=m;
    for(int i=1;i<=n;i++)
    {
        cout<<"OK\n";
    }
    for(int i=n+1;i<=m;i++)
    {
        cout<<"Too Many Requests\n";
    }
    return 0;
} 