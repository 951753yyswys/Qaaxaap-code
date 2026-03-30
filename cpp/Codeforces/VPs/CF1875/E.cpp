#include<bits/stdc++.h>
using namespace std;
int ans=1e9,a,b,c,d,m;
void dfs(int dep,int x,int y,int lst)
{
    int lx=x;
    int ly=y;
    dep++;
    if(dep>8) return;
    for(int i=1;i<=4;i++)
    {
        if(i==lst) continue;
        x=lx,y=ly;
        if(i==1) x=x&y;
        if(i==2) x=x|y;
        if(i==3) y=x^y;
        if(i==4) y=y^m;
        if(x==c&&y==d) 
        {
            ans=min(ans,dep);
            return;
        }
        else dfs(dep,x,y,i);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ans=1e9;
        cin>>a>>b>>c>>d>>m;
        if(a==c&&b==d) ans=0;
        else dfs(0,a,b,-1);
        if(ans==1e9) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
