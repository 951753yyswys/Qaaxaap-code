#include<bits/stdc++.h>
using namespace std;
#define int long long
bool check(vector<int> a)
{
    int flag=0;
    int n=a.size();
    for(int i=1;i<n;i++)
    {
        if(flag==0)
        {
            if(a[i-1]>a[i]) flag=1;
        }
        if(flag==1)
        {
            if(a[i-1]<a[i]) return 0;
        }
    }
    return 1;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) a[i]=i+1;
        int cnt=0,flag=1;
        while(flag) 
        {
            if(check(a)) cnt++;
            if(cnt==k) break;
            flag=next_permutation(a.begin(),a.end());
        }
        if(flag==0) cout<<-1;
        else for(auto tmp:a) cout<<tmp<<' ';
        cout<<endl;
    }
    return 0;
} 