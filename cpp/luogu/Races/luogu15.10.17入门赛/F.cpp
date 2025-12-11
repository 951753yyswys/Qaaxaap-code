#include<bits/stdc++.h>
using namespace std;
int a[101010],t[101010];
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(q--)
    {
        int m,ans=0;
        cin>>m;
        for(int i=0;i<=m;i++) t[i]=0;
        for(int i=1;i<=n;i++) t[a[i]%m]=1;
        for(int i=0;i<=m;i++) ans+=t[i];
        cout<<ans<<'\n';
    }
    return 0;
}