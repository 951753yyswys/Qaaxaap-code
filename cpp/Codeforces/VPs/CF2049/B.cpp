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
        deque<char> zhq;
        for(int i=1;i<=n;i++)
        {
            char zh;
            cin>>zh;
            zhq.push_back(zh);
        }
        int cntl=1,cntr=1;
        while(!zhq.empty()&&zhq.front()=='s'&&cntl) 
            zhq.pop_front(),cntl^=1;
        while(!zhq.empty()&&zhq.back()=='p'&&cntr)
            zhq.pop_back(),cntr^=1;
        if(zhq.empty()) 
        {
            cout<<"Yes\n";
            continue;
        }
        int flag=1;
        char ls='#';
        while(!zhq.empty())
        {
            if(zhq.front()=='.')
            {
                zhq.pop_front();
                continue;
            }
            if(ls=='#') ls=zhq.front();
            if(ls!=zhq.front()) flag=0;
            zhq.pop_front();
        }
        if(flag) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
} 