#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=676767677;
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for (int i=0;i<n;i++) cin>>a[i];
        int ans=0;
        int stmp[2]={a[n-1],a[n-1]-1};
        for(int S:stmp) 
        {
            if(S<0||S>n)continue; 
            int pb=0;
            bool flag=1;
            for(int i=0;i<n;i++) 
            {
                int b_i=a[i]-pb-(n-i)+S;
                if(b_i<0||b_i>i+1||b_i<pb||b_i>pb+1) 
                {
                    flag=0;
                    break;
                }
                pb=b_i;
            }
            if(flag&&pb==S) ans++;
        }
        cout<<ans<< "\n";
    }
    return 0;
}