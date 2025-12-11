#include<bits/stdc++.h>
using namespace std;
#define int long long
int pri[1010100],en,ispri[1010100],mipri[1010100];
void pre()
{
    for(int i=1;i<=1000000;i++) ispri[i]=1;
    for(int i=2;i<=1000000;i++) 
    {
        if(ispri[i]) pri[++en]=i,mipri[i]=i;
        for(int j=1;j<=en;j++)
        {
            if(pri[j]*i>1000000) break;
            if(!ispri[pri[j]*i]) break;
            ispri[i*pri[j]]=0,mipri[i*pri[j]]=pri[j];
            if(i%pri[j]==0) break;
        }
    }
}
vector<int> fpris(int n)
{
    vector<int> ykyk;
    if(n==1) return ykyk;
    int tmp=n;
    while(tmp>1)
    {
        int p=mipri[tmp];
        ykyk.push_back(p);
        while(tmp%p==0) tmp/=p;
    }
    return ykyk;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    pre();
    //for(int i=1;i<=100;i++) cout<<mipri[i]<<' ';
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        int mx=0,pl=0,brk=0;
        vector<bool> zlr(202020,0); 
        for(int i=0;i<n;i++)
        {
            vector<int> yk=fpris(a[i]);
            for(auto p:yk) 
            {
                mx=max(mx,zlr[p]+1ll);
                if(zlr[p]==1) break;
                zlr[p]=1;
            }
            if(mx>=2) break;
        }
        if(mx>=2) cout<<0<<endl;
        else
        {
            for(int i=0;i<n;i++)
            {
                vector<int> yk=fpris(a[i]+1);
                for(auto p:yk) 
                {
                    if(p>200001) continue;
                    mx=max(mx,zlr[p]+1ll);
                    if(zlr[p]==1) break;
                }
                if(mx>=2) break;
            }
            if(mx>=2) cout<<1<<endl;
            else cout<<2<<endl;
        }
    }
    return 0;
} 