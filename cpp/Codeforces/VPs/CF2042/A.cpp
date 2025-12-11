#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(int x,int y){return x>y;};
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
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a.begin(),a.end(),cmp);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(sum+a[i]>k) break;
            sum+=a[i];
        }
        cout<<k-sum<<endl;
    }
    return 0;
} 