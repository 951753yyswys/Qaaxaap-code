#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        bool flag=1;
        for(int i=1;i+1<=n;i+=2) 
            if(a[i]!=a[i+1]) flag=0;
        for(int i=2;i+1<=n;i+=2) 
            if(a[i]==a[i+1]) flag=0;
        if(flag) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}