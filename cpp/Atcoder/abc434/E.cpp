#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace DS
{
    class DSU 
    {
    public:
        vector<int> p,sz;
        DSU(int n) 
        { 
            p.resize(n);
            sz.resize(n);
            for(auto &tmp:sz) tmp=1;
            for(int i=0;i<n;i++) p[i]=i;
        }
        ~DSU()=default;
        int find(int x) 
        {
            if(p[x]==x) return x;
            return p[x]=find(p[x]);
        }
        void unite(int a,int b) 
        {
            a=find(a);
            b=find(b);
            if(a==b) return;
            if(sz[a]<sz[b]) swap(a,b);
            p[b]=a;
            sz[a]+=sz[b];
        }
    };    
}
using namespace DS;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    int gi(int x,vector<int> &usf)
    {
        return lower_bound(usf.begin(),usf.end(),x)-usf.begin();
    }
    void work()
    {
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        vector<int> usf;
        for(int i=0;i<n;i++) 
        {
            int x,r;
            cin>>x>>r;
            a[i]=x-r;
            b[i]=x+r;
            usf.push_back(a[i]);
            usf.push_back(b[i]);
        }
        sort(usf.begin(),usf.end());
        usf.erase(unique(usf.begin(),usf.end()),usf.end());
        int m=usf.size();
        DSU dsu(m);
        vector<pair<int,int>> g;
        for(int i=0;i<n;i++) 
        {
            int u=gi(a[i],usf);
            int v=gi(b[i],usf);
            g.push_back({u,v});
            dsu.unite(u,v);
        }
        vector<int> ec(m);
        for(auto &e:g) 
        {
            int u=e.first;
            int v=dsu.find(u);
            ec[v]++;
        }
        int ans=0;
        for(int v=0;v<m;v++) if(dsu.find(v)==v) ans+=min(dsu.sz[v],ec[v]);
        cout<<ans<<endl;
    }
}
signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}
