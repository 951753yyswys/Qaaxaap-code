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
bool cmp(pair<int,int> xx,pair<int,int> yy)
{
    if(xx.first!=yy.first) 
    return xx.first<yy.first;
    return xx.second<yy.second;
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
        vector<pair<int,int>> ls(n);
        for(int i=0;i<n;i++) cin>>ls[i].second;
        for(int i=0;i<n;i++) cin>>ls[i].first;
        sort(ls.begin(),ls.end(),cmp);
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) a[i]=ls[i].second;
        for(int i=0;i<n;i++) b[i]=ls[i].first;
        if(b[0]==0) 
        {
            cout<<0<<endl;
            continue;
        }
        int mx=0,pl=0,ans=0,nin=0,brk=0;
        vector<bool> zlr(202020,0);
        set<int> num; 
        for(int i=0;i<n;i++)
        {
            vector<int> yk=fpris(a[i]);
            for(auto p:yk) 
            {
                if(zlr[p])
                {
                    brk=1;
                }
                else if(i) num.insert(p);
                zlr[p]=1;
            }
        }
        if(brk) cout<<0<<endl;
        else
        {
            ans=b[0]+b[1];
            for(int i=0;i<n;i++)
            {
                if(b[i]>ans) break;
                vector<int> yk=fpris(a[i]+1);
                for(auto p:yk) 
                {
                    if(p>200001) continue;
                    if(zlr[p]==1) 
                    {
                        ans=min(ans,b[i]);
                        brk=1;
                        break;
                    }
                }
                if(brk) break;
            }
            for(auto p:num)
            {
                //if((p-a[0])*b[0]>ans) break;
                ans=min(ans,b[0]*(p-a[0]%p));
            }
            cout<<ans<<endl;
        }
    }
    return 0;
} 