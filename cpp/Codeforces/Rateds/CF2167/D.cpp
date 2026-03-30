#include<bits/stdc++.h>
#define int long long 
using namespace std;
vector<int> pri;
bool not_prime[501010];
void pre(int n) 
{
    for(int i=2;i<=n;i++) 
    {
        if(!not_prime[i]) 
            pri.push_back(i);
        for(int pri_j:pri) 
        {
            if(i*pri_j>n) break;
            not_prime[i*pri_j]=1;
            if(i%pri_j==0)
                break;
        }
    }
}
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    pre(10000);
    if(pri.size()>25) 
        pri.resize(25);
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        vector<int> a(n);        
        bool has=0;
        for(auto &tmp:a) 
        {
            cin>>tmp;
            if(tmp==1) 
                has=1;
        }
        if(has) 
        {
            cout<<2<<"\n";
            continue;
        }
        int ans=1e18+1;
        for(auto num:a) 
        {
            for(auto p:pri) 
            {
                if(num%p!=0) 
                {
                    ans=min(ans,p);
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}