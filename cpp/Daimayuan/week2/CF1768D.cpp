//i 与 pos_i - 经典 trick！
#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace DS
{
    template<typename T>
    class DSU
    {
    public:
        vector<int> fa;
        DSU(vector<int> &a)
        {
            int n=a.size()-1;
            fa.resize(n+2);
            for(int i=1;i<=n;i++) fa[i]=i;
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
        cin>>t;
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
            for(int i=1;i<=n;i++) if(dsu.find(i)==i) cnt++;
            cout<<n-cnt+flag<<endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}