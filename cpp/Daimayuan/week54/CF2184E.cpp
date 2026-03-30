#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace DS {
    class DSU {
    public:
        vector<int> fa, mi, mx;
        DSU(int n) {
            mi.resize(n + 1);
            mx.resize(n + 1);
            fa.resize(n + 1);
            for (int i = 1; i <= n; i++) {
                mi[i] = mx[i] = fa[i] = i;
            }
        }
        int find(int x) {
            if (x == fa[x])
                return x;
            return fa[x] = find(fa[x]);
        }
        void unite(int x, int y) {
            x = find(x);
            y = find(y);
            fa[y] = x;
            mi[x] = min(mi[x], mi[y]);
            mx[x] = max(mx[x], mx[y]);
        }
        int qmin(int x) {
            x = find(x);
            return mi[x];
        }
        int qmax(int x) {
            x = find(x);
            return mx[x];
        }
    };
} // namespace DS
using namespace DS;
namespace Qaaxaap {
    void work() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            DSU ds(n);
            vector<int> p(n + 1), ans(n);
            vector<vector<int>> buc(n);
            for (int i = 1; i <= n; i++) {
                cin >> p[i];
                if (i > 1) {
                    buc[abs(p[i - 1] - p[i])].push_back(i);
                }
            }
            int as = 0;
            for (int i = n - 1; i > 0; i--) {
                for (auto d : buc[i]) {
                    int ll = ds.qmin(d - 1);
                    int lr = d - 1;
                    int rl = d;
                    int rr = ds.qmax(d);
                    int lenl = lr - ll + 1;
                    int lenr = rr - rl + 1;
                    as -= lenl * (lenl - 1) / 2 + lenr * (lenr - 1) / 2;
                    as += (lenl + lenr) * (lenl + lenr - 1) / 2;
                    ds.unite(d, d - 1);
                }
                ans[i] = as;
            }
            for (int i = 1; i < n; i++) {
                cout << ans[i] << ' ';
            }
            cout << endl;
        }
    }
} // namespace Qaaxaap
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Qaaxaap::work(), 0;
}
