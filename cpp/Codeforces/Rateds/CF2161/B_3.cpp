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
        int n,tril=0,flag=0;
        cin>>n;
        vector<int> sumh(n+5),suml(n+5);
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
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                sumh[i]+=mp[i][j];
                if(sumh[i]>=3) flag=1;
            }
        for(int j=1;j<=n;j++)
            for(int i=1,sum=0;i<=n;i++)
            {
                suml[j]+=mp[i][j];
                if(suml[j]>=3) flag=1;
            }
        if(flag)
        {
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=2;i<n;i++)
            for(int j=1;j<=n;j++)
                if(mp[i-1][j]&&mp[i+1][j]) flag=1;
        for(int i=1;i<=n;i++)
            for(int j=2;j<n;j++)
                if(mp[i][j-1]&&mp[i][j+1]) flag=1;   
        if(flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
} 