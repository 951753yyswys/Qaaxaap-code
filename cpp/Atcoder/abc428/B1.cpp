#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    string s;
    cin>>n>>k>>s;
    s='#'+s;
    set<string> all;
    map<string,int> cnt; 
    for(int i=1;i+k-1<=n;i++)
    {
        string tmp="";
        for(int j=1;j<=k;j++) tmp+=s[i+j-1];
        all.insert(tmp);
        cnt[tmp]++;
    }
    int ans=0;
    for(auto i:cnt) ans=max(ans,i.second);
    cout<<ans<<endl;
    for(auto i:all)
    {
        if(cnt[i]==ans) cout<<i<<' ';
    }
    return 0;
}