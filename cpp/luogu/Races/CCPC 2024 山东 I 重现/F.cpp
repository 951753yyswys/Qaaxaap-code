#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int main()
{
    int n;
    cin>>n;
    // 
    // if(n==3) cout<<"Yes\n3 2 6\n4 3 3\n3 1 5";
    // if(n==4) cout<<"Yes\n1 8 2 8\n8 3 8 4\n5 8 5 8\n6 8 7 8";
    // if(n==5) cout<<"Yes\n1 9 2 9 3\n9 4 9 5 9\n6 9 6 9 6\n9 7 9 8 9\n9 9 9 9 9";
    // if(n==6) cout<<"Yes\n";
    // return 0;
    int cnt=0;
    for(int i=1;i<=n;i+=2) a[1][i]=++cnt;
    for(int i=2;i<=n;i+=2) a[2][i]=++cnt;
    if(n==2) cout<<"Yes\n1 2\n3 4";
    else
    {
        cout<<"Yes\n";
        cnt++;
        for(int i=1;i<=n;i+=1) a[3][i]=cnt;
        // cnt++;
        // for(int i=2;i<=n;i+=2) a[3][i]=cnt;
        for(int j=4;j<=n;j++) 
        {
            cnt++;
            for(int i=1;i<=n;i++) a[j][i]=cnt;
        }
        cnt++;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(!a[i][j]) a[i][j]=cnt;
        // a[n][1]=cnt-2;
        // a[n][3]=cnt-3;
        for(int i=1;i<=2;i++) for(int j=1;j<=n;j++) if(a[i][j]==cnt) a[i][j]=n+n;
        a[2][1]=cnt; 
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) cout<<a[i][j]<<' ';
            cout<<'\n';
        }
    }
    return 0;
}