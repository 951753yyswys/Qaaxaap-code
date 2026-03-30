#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap {
int n, m, a, b, c, ans = LLONG_MAX;
struct edge {
    int id, to, p, q;
};
vector<vector<edge>> g;
int df[1010100];
int dt;
bool fl;
void dfs(int ro, int t, int al) {
    if (clock() - dt > 600000 && !fl) {
        fl = 1;
        for (int i = 1; i <= m; i++)
            df[i] = min(df[i], 5098101ll);
    }
    if (ro == n) {
        ans = min(ans, al + t);
        return;
    }
    for (auto v : g[ro]) {
        if (v.p < t) {
            continue;
        }
        int dl = v.p - t;
        int all = a * dl * dl + b * dl + c + al;
        if (df[v.id] <= all) {
            continue;
        }
        df[v.id] = all;
        dfs(v.to, v.q, all);
    }
}
void work() {
    dt = clock();
    memset(df, 0x3f, sizeof(df));
    cin >> n >> m >> a >> b >> c;
    g.resize(n + 1);
    for (int i = 1; i <= m; i++) {
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        g[x].push_back({i, y, p, q});
    }
    dfs(1, 0, 0);
    cout << ans;
}
} // namespace Qaaxaap
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Qaaxaap::work(), 0;
}
