#include<bits/stdc++.h>
using namespace std;
int ans[202020];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    for(int i=1;i<=202010;i++) 
    {
            int tmp=i;
            while(tmp)
            {
                ans[i]+=tmp%10;
                tmp/=10;
            }
    }
    for(int i=2;i<=202010;i++) ans[i]+=ans[i-1];
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<ans[n]<<endl;
    }
    return 0;
}