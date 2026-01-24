#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap {
    int v[1000005], dist[1000005], lc[1000005], rc[1000005];
    int merge(int x, int y) {
        if (!x || !y)
            return x + y;
        if (v[y] < v[x])
            swap(x, y);
        rc[x] = merge(rc[x], y);
        if (dist[lc[x]] < dist[rc[x]])
            swap(lc[x], rc[x]);
        dist[x] = dist[rc[x]] + 1;
        return x;
    }
    pair<int, int> split(int x) {
        int l = lc[x], r = rc[x];
        lc[x] = rc[x] = 0;
        dist[x] = 0;
        return make_pair(l, r);
    }
    void work() {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> v[i];
        while (m--) {
            int op;
            cin >> op;
            if (op == 1) {
                int x, y;
                cin >> x >> y;
                if (x && y)
                    cout << v[merge(x, y)] << "\n";
                else
                    cout << "-1\n";
            } else {
                int x;
                cin >> x;
                if (!x)
                    continue;
                pair<int, int> t = split(x);
                merge(t.first, t.second);
            }
        }
    }
} // namespace Qaaxaap
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Qaaxaap::work(), 0;
}
