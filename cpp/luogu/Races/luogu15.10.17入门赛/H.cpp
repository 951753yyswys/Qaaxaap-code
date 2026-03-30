#include<bits/stdc++.h>
using namespace std;
string s[101001];
int mp[101001][101];
char ans[101001][101];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) 
    ans[i][j]='#';
    for(int i=1;i<=n;i++) cin>>s[i],s[i]='#'+s[i];
    for(int j=1;j<=m;j++)
    {
        int mx=n+1;
        //mp[n][j]=n+1;
        mp[n+1][j]=n+1;
        for(int i=n;i>=1;i--)
        {
            if(s[i][j]=='-') mp[i][j]=i,mx=i;
            else if(s[i][j]=='.') mp[i][j]=mp[i+1][j];
            else mp[i][j]=mp[i+1][j]-1;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        //if(ans[i][mp[j][i]]!='#')
        if(s[j][i]!='.')
        ans[mp[j][i]][i]=s[j][i];
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
    if(ans[i][j]=='#') ans[i][j]='.';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cout<<ans[i][j];
        cout<<endl;
    }
    return 0;
}