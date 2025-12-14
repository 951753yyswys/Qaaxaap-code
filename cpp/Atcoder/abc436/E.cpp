#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace DS
{
    template<typename T>
    class DSU
    {
    public:
        vector<int> fa,siz;
        DSU(vector<int> &a)
        {
            int n=a.size()-1;
            fa.resize(n+2);
            siz.resize(n+2);
            for(int i=1;i<=n;i++) siz[i]=1,fa[i]=i;
        }
        int find(int x)
        {
            if(fa[x]==x) return x;
            return fa[x]=find(fa[x]);
        }
        bool merge(int x,int y)
        {
            int fx=find(x);
            int fy=find(y);
            if(fx==fy) return 0;
            fa[fx]=fy;
            siz[fy]+=siz[fx];
            return 1;
        }
        bool same(int x,int y)
        {
            int fx=find(x);
            int fy=find(y);
            return fx==fy;
        }
    };
}
using namespace DS;
namespace Qaaxaap
{
    const int N=5e5,mod=998244353;
    void work()
    {
        int t;
        t=1;
        while(t--)
        {
            int n;
            cin>>n;
            vector<int> p(n+1),pos(n+1);
            for(int i=1;i<=n;i++) cin>>p[i],pos[p[i]]=i;
            DSU<int> dsu(p);
            int cnt=0;
            for(int i=1;i<=n;i++) 
            {
                if(i==pos[i]) continue;
                dsu.merge(i,pos[i]);
            }
            int flag=1;
            for(int i=1;i<n;i++) if(dsu.same(i,i+1)) flag=-1;
            for(int i=1;i<=n;i++) if(dsu.find(i)==i) cnt+=dsu.siz[i]*(dsu.siz[i]-1)/2;
            cout<<cnt<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}