#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() 
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        vector<string> mp(n);
        for(auto &tmp:mp) cin>>tmp;
        if(n<=2) 
        {
            cout<<"YES"<<endl;
            continue;
        }
        bool flag=0;
        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<=n-3;j++) 
            {
                if(mp[i][j]=='#'&&mp[i][j+1]=='#'&&mp[i][j+2]=='#') 
                {
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) 
        {
            cout<<"NO"<<endl;
            continue;
        }
        for(int j=0;j<n;j++) 
        {
            for(int i=0;i<=n-3;i++) 
            {
                if(mp[i][j]=='#'&&mp[i+1][j]=='#'&&mp[i+2][j]=='#') 
                {
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) 
        {
            cout<<"NO"<<endl;
            continue;
        }
        bool flagp=0;
        for(int i=0;i<n;i++) 
        {
            vector<int> coll;
            for(int j=0;j<n;j++)
                if(mp[i][j]== '#')
                    coll.push_back(j);
            if(coll.size()>=2) 
            {
                sort(coll.begin(),coll.end());
                for(int k=0;k<coll.size()-1;k++)
                    if(coll[k+1]-coll[k]==2) 
                    {
                        flagp=1;
                        break;
                    }
            }
            if(flagp) break;
        }
        if(flagp) 
        {
            cout <<"NO"<<endl;
            continue;
        }
        for(int j=0;j<n;j++) 
        {
            vector<int> row;
            for(int i=0;i<n;i++)
                if(mp[i][j]=='#')
                    row.push_back(i);
            if(row.size()>=2) 
            {
                sort(row.begin(),row.end());
                for(int k=0;k<row.size()-1;k++) 
                    if(row[k+1]-row[k]==2) 
                    {
                        flagp=1;
                        break;
                    }
            }
            if(flagp) break;
        }
        if(flagp) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}