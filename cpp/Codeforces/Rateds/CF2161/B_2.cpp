#include<bits/stdc++.h>
using namespace std;
#define int long long
int mp[114][114];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,tril=0,squ=0;
        cin>>n;
        for(int i=0;i<=n+5;i++) 
            for(int j=0;j<=n+5;j++) 
                mp[i][j]=0;
        for(int i=1;i<=n;i++) 
            for(int j=1;j<=n;j++)
            {
                char l;
                cin>>l;
                if(l=='#') 
                    mp[i][j]=1,tril++;
                else 
                    mp[i][j]=0;
            }
        int ans=0;
        for(int i=1;i<n;i++)
            for(int j=1;j<n;j++)
                if(mp[i][j+1]==1&&mp[i][j]==1&&mp[i+1][j+1]==1&&mp[i+1][j]==1)
                    squ=1;
        if(squ)
        {
            if(tril==4)
                cout<<"YES"<<endl;
            else 
                cout<<"NO"<<endl;
            continue;
        }
        for(int st=1;st<=n;st++)
        {
            int sum=0;
            for(int i=1,j=st;j<=n&&i<=n;i++,j++) 
                sum+=mp[i][j]+mp[i+1][j];
            if(sum==tril) ans=1;
            sum=0;
            for(int i=1,j=st;j<=n&&i<=n;i++,j++) 
                sum+=mp[i][j]+mp[i][j+1];
            if(sum==tril) ans=1;
            sum=0;
            for(int i=1,j=st;j>=1&&i<=n;i++,j--) 
                sum+=mp[i][j]+mp[i][j+1];
            if(sum==tril) ans=1;
            sum=0;
            for(int i=1,j=st;j>=1&&i<=n;i++,j--) 
                sum+=mp[i][j]+mp[i+1][j];
            if(sum==tril) ans=1;
        }
        for(int st=1;st<=n;st++)
        {
            int sum=0;
            for(int i=1,j=st;j<=n&&i<=n;i++,j++) 
                sum+=mp[j+1][i]+mp[j][i];
            if(sum==tril) ans=1;
            sum=0;
            for(int i=1,j=st;j<=n&&i<=n;i++,j++) 
                sum+=mp[j][i+1]+mp[j][i];
            if(sum==tril) ans=1;
            sum=0;
            for(int i=1,j=st;j>=1&&i<=n;i++,j--) 
                sum+=mp[j][i+1]+mp[j][i];
            if(sum==tril) ans=1;
            sum=0;
            for(int i=1,j=st;j>=1&&i<=n;i++,j--) 
                sum+=mp[j+1][i]+mp[j][i];
            if(sum==tril) ans=1;
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
} 