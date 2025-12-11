#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pir pair<int,int>
pir exgcd(int a,int b)
{
    if(b==0) return {1,0};
    pir lans=exgcd(b,a%b);
    int x=lans.second;
    int y=lans.first-(a/b)*lans.second;
    return {x,y};
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int gc=__gcd(a,b);
        if(c%gc!=0)
        {
            cout<<-1<<endl;
            continue;
        }
        pir ans=exgcd(a,b);
        int x=ans.first;
        int y=ans.second;
        x*=c/gc;
        y*=c/gc;
        int mix=(x+c*b/gc)%(b/gc);
        int miy=(y+c*a/gc)%(a/gc);
        if(mix==0) mix=b/gc;
        if(miy==0) miy=a/gc;
        int mxy=(c-mix*a)/b;
        int mxx=(c-miy*b)/a;
        if(mxy<=0||mxx<=0)
        {
            
            cout<<mix<<' '<<miy<<endl;
            continue;
        }
        int num=(mxy-miy)/(a/gc)+1;
        cout<<num<<' '<<mix<<' '<<miy<<' '<<mxx<<' '<<mxy<<' '<<endl;
    }
    return 0;
} 