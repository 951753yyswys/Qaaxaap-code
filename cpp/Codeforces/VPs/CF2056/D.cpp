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
        vector<int> a(n),b(n),cnt(2*n+2);
        for(int i=0;i<n;i++) cin>>a[i];
        int bad=0;
        for(int x=1;x<=10;x++)
        {
            for(int i=0;i<n;i++) 
            {
                if(b[i]>x) b[i]=1;
                else b[i]=-1;
            }
            int sum=n+1;
            for(int i=0;i<n;i++)
            {
                cnt[sum]++;
                sum+=b[i];
            }
            int lans=0;
            sum=n;
            for(int i=0;i<n;i++) 
            {
                lans+=cnt[sum+b[i]];
            }
        }
    }
    return 0;
} 