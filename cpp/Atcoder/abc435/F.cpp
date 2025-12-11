#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace Qaaxaap
{
    using ll = long long;
    template<typename T>
    class FHQ
    {
    private:
        struct node
        {
            T val, dp0, dp1;
            ll pri;
            int ls, rs;  
            node(int v, int p) : val(v), pri(p), ls(-1), rs(-1), dp0(-v), dp1(v) {}
            node() = default;
        };
        vector<node> nodes;  
        int rt;  
        int merge(int x, int y)
        {
            if (x == -1) return y;
            if (y == -1) return x;
            
            if (nodes[x].pri > nodes[y].pri) 
            {
                if (nodes[x].val < nodes[y].val) 
                    nodes[x].rs = merge(nodes[x].rs, y);
                else 
                    nodes[x].ls = merge(nodes[x].ls, y);
                return x;
            }
            else 
            {
                if (nodes[y].val < nodes[x].val) 
                    nodes[y].rs = merge(nodes[y].rs, x);
                else 
                    nodes[y].ls = merge(nodes[y].ls, x);
                return y;
            }
        }
        void split(int ro, int val, int& lrt, int& rrt)
        {
            if (ro == -1) 
            {
                lrt = rrt = -1;
                return;
            }
            if (nodes[ro].val < val)
            {
                int tmp;
                split(nodes[ro].rs, val, tmp, rrt);
                nodes[ro].rs = tmp;
                lrt = ro;
            }
            else 
            {
                int tmp;
                split(nodes[ro].ls, val, lrt, tmp);
                nodes[ro].ls = tmp;
                rrt = ro;
            }
        }
        int _dfs(int ro)
        {
            if (ro == -1) return 0;
            int dp = 0;
            if (nodes[ro].ls != -1) 
                dp = max(dp, _dfs(nodes[ro].ls));
            if (nodes[ro].rs != -1) 
                dp = max(dp, _dfs(nodes[ro].rs));
            if (nodes[ro].ls != -1) 
                dp = max(dp, nodes[ro].val - nodes[nodes[ro].ls].dp0);
            if (nodes[ro].rs != -1) 
                dp = max(dp, nodes[nodes[ro].rs].dp1 - nodes[ro].val);
            nodes[ro].dp0 = -dp + nodes[ro].val;
            nodes[ro].dp1 = dp + nodes[ro].val;
            return dp;
        }
        
    public:
        FHQ() : rt(-1) {}
        void insert(T val, ll pri)
        {
            nodes.push_back(val, pri);
            int nd = nodes.size() - 1;
            int lrt = -1, rrt = -1, tmp = -1;
            
            split(rt, val, lrt, rrt);
            tmp = merge(lrt, nd);
            lrt = tmp;
            rt = merge(lrt, rrt);
        }
        void build(vector<int>& w)
        {
            int n = w.size();
            nodes.clear();
            nodes.reserve(n);
            vector<int> stk;
            for (int i = 0; i < n; i++)
            {
                int last=-1;
                while (!stk.empty() && w[stk.back()] < w[i])
                {
                    last = stk.back();
                    stk.pop_back();
                }
                nodes.emplace_back(i, w[i]);
                int cur = nodes.size()-1;
                nodes[cur].ls = last;
                if (!stk.empty()) nodes[stk.back()].rs = cur;
                stk.push_back(cur);
            }
            rt = stk.empty() ? -1 : stk[0];
        }
        int dfs()
        {
            return _dfs(rt);
        }
    };
    const int N=5e5,mod=998244353;
    void work()
    {
        FHQ<int> t;
        int n,cnt=0;
        cin>>n;
        vector<int> p(n);
        for(auto &tmp:p) cin>>tmp;
        t.build(p);
        cout<<t.dfs();
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    return Qaaxaap::work(),0;
}