#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    void work()
    {
        int T;
        cin>>T;
        while(T--) 
        {
            int n,q;
            cin>>n>>q;
            string s;
            cin>>s;
            int b=0;
            for(int i=0;i<n;i++) 
            {
                char c=s[i];
                if(c=='?') c='I';
                if(c=='X') b+=10;
                else if(c=='V') b+=5;
                else 
                { 
                    if(i+1<n) 
                    {
                        char nxt=s[i+1];
                        if(nxt=='?') nxt='I';
                        if(nxt=='X'||nxt=='V') b-=1;
                        else b+=1;
                    } 
                    else b+=1;
                }
            }
            vector<int> twh;
            for(int i=0;i<n;i++) if(s[i]=='?') twh.push_back(i);
            int m=twh.size();
            vector<int> f(m+1,0);  
            if(m>0) 
            {
                vector<int> a(m,4); 
                vector<vector<int>> g(m);
                vector<int> idx(n,-1);
                for(int j=0;j<m;j++) idx[twh[j]]=j;
                for(int j=0;j<m;j++) 
                {
                    int p=twh[j];
                    if(p+1<n&&s[p+1]!='?') if(s[p+1]=='X'||s[p+1]=='V') a[j]+=2;
                    if(p-1>=0) 
                    {
                        if(s[p-1]!='?') 
                        {
                            if(s[p-1]=='I') a[j]-=2;
                        } 
                        else 
                        {
                            a[j]-=2;
                            int k=idx[p-1];
                            g[j].push_back(k);
                            g[k].push_back(j);
                        }
                    }
                }
                vector<int> vis(m);
                priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
                for(int j=0;j<m;j++) q.push({a[j],j});
                for(int i=1;i<=m;i++)
                {
                    int ch=-1,num=0;
                    while(1) 
                    {
                        auto [cst,id]=q.top();
                        q.pop();
                        if(!vis[id]&&cst==a[id]) 
                        {
                            ch=id;
                            num=cst;
                            break;
                        }
                    }
                    vis[ch]=1;
                    f[i]=f[i-1]+num;
                    for(int nb:g[ch]) if(!vis[nb]) 
                    {
                        a[nb]+=2;
                        q.push({a[nb],nb});
                    }
                }
            }
            while(q--) 
            {
                int cx,cv,ci;
                cin>>cx>>cv>>ci;
                int i=0;
                if(ci>=m) i=0;
                else i=m-ci; 
                int dv=f[i];              
                int dx=max(0ll,i-cv);    
                int ans=b+dv+5LL*dx;
                cout<<ans<<endl;
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}
