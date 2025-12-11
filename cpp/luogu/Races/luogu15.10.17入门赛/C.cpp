#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n==0) cout<<"No";
    while(n%10==0) n/=10;
    if(n>=10) cout<<"No";
    else cout<<"Yes";
    return 0;
}