#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[114];
bool cmp(int x,int y)
{
    return x>y;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int col=a[1];
    sort(a+1,a+n*m+1,cmp);
    int c,r;
    int pul=0;
    for(int i=1;i<=m;i++)
    {
        if(i%2) for(int j=1;j<=n;j++)
        {
            pul++;
            if(a[pul]==col) 
            {
                r=j;
                c=i;break;
            }
            
        }
        else for(int j=n;j>=1;j--)
        {
            pul++;
            if(a[pul]==col) 
            {
                r=j;
                c=i;break;
            }
            
        }
    }
    cout<<c<<' '<<r;
    return 0;
} 