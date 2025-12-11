#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
int main()
{
    string x,y;
    cin>>x>>y;
    m["Ocelot"]=1;
    m["Serval"]=2;
    m["Lynx"]=3;
    if(m[x]>=m[y]) cout<<"Yes";
    else cout<<"No";
    return 0;
}