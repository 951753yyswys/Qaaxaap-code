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
        int n,k;
        cin>>n>>k;
        int l2=__lg(k);
        if(l2>=n) 
        {
            cout<<-1<<endl;
            continue;
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            int zhq=1,zh=0,len=(1ll<<n-1-i);
            while(zh+len<k)
            {//cout<<"len:"<<len<<endl;
                len>>=1;
                zh+=len;
                zhq++;
            }
            cout<<zh<<endl;
            ans[i]=zhq;
            k-=zh;
        }
        for(auto tmp:ans) cout<<tmp<<' ';
        cout<<endl;
    }
    return 0;
} 