#include<bits/stdc++.h>
using namespace std;
int a[101010],b[101010];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    string s;
    cin>>s;
    int m=s.size();
    s='#'+s;
    int tril=m;
    while(s[tril]>'9'||s[tril]<'0') tril--;
    int trih=1;
    while(s[trih]>'9'||s[trih]<'0') trih++;
    int ans=0;
    for(int i=trih;i<=tril;i++)
    {
        ans*=10;
        ans+=s[i]-'0';
    }
    if(s[trih-2]=='a') ans=a[ans];
    else ans=b[ans];
    for(int i=trih-3;i>=1;i--)
    {
        if(s[i]=='a') ans=a[ans];
        if(s[i]=='b') ans=b[ans];
    }
    cout<<ans;
    return 0;
}