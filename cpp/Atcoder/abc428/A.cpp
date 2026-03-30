#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,a,b,x,ans=0;
    cin>>s>>a>>b>>x;
    ans+=x/(a+b)*s*a;
    ans+=min(x%(a+b),a)*s;
    cout<<ans;
    return 0;
}