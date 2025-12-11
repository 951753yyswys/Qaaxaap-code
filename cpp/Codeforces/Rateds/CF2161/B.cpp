#include<bits/stdc++.h>
using namespace std;
#define int long long
int mp[101][101];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,tril=0;
        cin>>n;
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
        int nn=n,nm=n;
        for(int i=n;i>=1;i--)
        {
            nn=i;
            int flag=1;
            for(int j=1;j<=i;j++)
                if(mp[i][j]) 
                    flag=0;
            if(!flag)  
                break;
        }
        for(int i=n;i>=1;i--)
        {
            nm=i;
            int flag=1;
            for(int j=1;j<=i;j++)
                if(mp[j][i]) 
                    flag=0;
            if(!flag) 
                break;
        }
        //cout<<n<<endl;
        int sum=0;
        for(int i=1;i<=n;i++) 
        {
            if(mp[i][i]) 
                sum++;
            if(mp[i+1][i]^mp[i-1][i])
                sum++;
            if(mp[i][i+1]^mp[i][i-1]) 
                sum++;
        }
        if(sum==tril)
        {
            cout<<"YES"<<endl;
            continue;
        }
        sum=0;
        for(int i=1;i<=n;i++) 
        {
            if(mp[n-i+1][i]) 
                sum++;
            if(mp[n-i][i]^mp[n-i+2][i])
                sum++;
            if(mp[n-i+1][i+1]^mp[n-i+1][i-1]) 
                sum++;
        }
        if(sum==tril)
        {
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
    return 0;
} 