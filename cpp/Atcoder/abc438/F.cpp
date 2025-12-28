#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap
{
    const int INF=(int)4e18;
    struct LCA
    {
        int n,logg;
        vector<vector<int>> up;
        vector<int> dep;
        vector<vector<int>> g;
        void init(const vector<vector<int>>& adj, int root)
        {
            g = adj;
            n = (int)g.size();
            logg = 1;
            while((1LL<<logg) <= n) logg++;
            up.assign(logg, vector<int>(n, -1));
            dep.assign(n, 0);
            vector<int> pa(n, -1);
            vector<int> stk;
            stk.reserve(n);
            stk.push_back(root);
            pa[root] = root;
            for(int i=0;i<(int)stk.size();i++)
            {
                int v = stk[i];
                for(int to: g[v])
                {
                    if(to == pa[v]) continue;
                    pa[to] = v;
                    dep[to] = dep[v] + 1;
                    stk.push_back(to);
                }
            }
            for(int v=0; v<n; v++) up[0][v] = pa[v];
            for(int k=1; k<logg; k++)
                for(int v=0; v<n; v++)
                    up[k][v] = up[k-1][ up[k-1][v] ];
        }
        int lift(int v, int steps) const
        {
            for(int k=0;k<logg;k++)
                if(steps & (1LL<<k))
                    v = up[k][v];
            return v;
        }
        int lca(int a, int b) const
        {
            if(dep[a] < dep[b]) swap(a,b);
            a = lift(a, dep[a]-dep[b]);
            if(a==b) return a;
            for(int k=logg-1;k>=0;k--)
            {
                if(up[k][a] != up[k][b])
                {
                    a = up[k][a];
                    b = up[k][b];
                }
            }
            return up[0][a];
        }
        int dist(int a, int b) const
        {
            int c = lca(a,b);
            return dep[a] + dep[b] - 2LL*dep[c];
        }
        bool onp(int x, int a, int b) const
        {
            return dist(a,x) + dist(x,b) == dist(a,b);
        }
    };
    int n;
    vector<vector<int>> adj;
    vector<int> pa_,dep_,ord_,sub_;
    LCA lca_;
    void build(int root)
    {
        pa_.assign(n, -1);
        dep_.assign(n, 0);
        ord_.clear();
        ord_.reserve(n);
        vector<int> stk;
        stk.reserve(n);
        stk.push_back(root);
        pa_[root] = root;
        for(int i=0;i<(int)stk.size();i++)
        {
            int v = stk[i];
            ord_.push_back(v);
            for(int to: adj[v])
            {
                if(to == pa_[v]) continue;
                pa_[to] = v;
                dep_[to] = dep_[v] + 1;
                stk.push_back(to);
            }
        }
        sub_.assign(n, 1);
        for(int i=n-1;i>=0;i--)
        {
            int v = ord_[i];
            for(int to: adj[v])
            {
                if(to == pa_[v]) continue;
                sub_[v] += sub_[to];
            }
        }
    }
    int np(int from, int to)
    {
        int c = lca_.lca(from, to);
        if(c != from) 
            return pa_[from];
        else
        {
            int nd = dep_[to] - (dep_[from] + 1);
            return lca_.lift(to, (int)nd);
        }
    }
    int csa(int u, int vn)
    {
        if(pa_[vn] == u) 
            return n - sub_[vn];
        else 
            return sub_[u];
    }

    void work()
    {
        cin >> n;
        adj.assign(n, {});
        for(int i=0;i<n-1;i++)
        {
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int root = 0;
        build(root);
        lca_.init(adj, root);
        int sp = n * (n + 1) / 2; 
        vector<int> avoid(n, 0);
        for(int v=0; v<n; v++)
        {
            int sum = 0;
            for(int to: adj[v])
            {
                if(to == pa_[v]) continue;
                int s = sub_[to];
                sum += s * (s + 1) / 2;
            }
            if(v != root)
            {
                int s = n - sub_[v];
                sum += s * (s + 1) / 2;
            }
            avoid[v] = sum;
        } 
        int a = 0, b = 0, D = 0;
        bool flag = true;
        int ans = 0;
        for(int m=1; m<=n; m++)
        {
            if(m >= 2 && flag)
            {
                int x = m - 1;
                int olda = a, oldb = b;
                int da = lca_.dist(a, x);
                int db = lca_.dist(b, x);
                if(da > D && da >= db)
                {
                    b = x;
                    D = da;
                    flag = lca_.onp(oldb, olda, b);
                }
                else if(db > D)
                {
                    a = x;
                    D = db;
                    flag = lca_.onp(olda, a, oldb);
                }
                else
                    flag = lca_.onp(x, a, b);
            }
            int gm=0;
            if(flag)
            {
                if(a==b) gm=sp-avoid[a];
                else
                {
                    int na = np(a, b);
                    int nb = np(b, a);
                    int sa = csa(a, na);
                    int sb = csa(b, nb);
                    gm=sa*sb;
                }
            }
            ans+=gm;
        }
        cout<<ans<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Qaaxaap::work(), 0;
}
