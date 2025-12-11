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
        int n,od=0,ev=0;
        cin>>n;
        vector<int> a(n);
        for(auto &tmp:a) cin>>tmp;
        for(int i=0;i<n;i++)
        {
            if(a[i]%2) od++;
            else ev++;
        }
        if(od==0||ev==0)
        {
            for(auto tmp:a) cout<<tmp<<' ';
            cout<<endl;
        }
        else
        {
            sort(a.begin(),a.end());
            for(auto tmp:a) cout<<tmp<<' ';
            cout<<endl;
        }
    }
    return 0;
} 