#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> ans(n);
        for(int i=1;i<=n;i++)
        {
            int hd=0;
            for(int j=1;j<=n;j++)
            {
                char l;
                cin>>l;    
                if((l=='1'&&i>j)||(l=='0'&&i<j)) hd++;
                
            }ans[hd]=i;
        }
        for(auto tmp:ans)
        {
            cout<<tmp<<' ';
        }
        cout<<endl;
    }
    return 0;
} 