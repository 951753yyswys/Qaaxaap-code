#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace DS {
class fenwick {
    vector<int> t;
    int n;
    int lowbit(int x) { return x & -x; }
    void add(int id, int val) {
        while (id <= n) {
            t[id] += val;
            id += lowbit(id);
        }
    }
    int ask(int id) {
        int sum = 0;
        while (id > 0) {
            sum += t[id];
            id -= lowbit(id);
        }
        return sum;
    }
    fenwick(int n) : t(n + 1), n(n) {}
};
} // namespace DS
using namespace DS;
namespace Qaaxaap {
const int mod = 998244353;
int yc[1010][11];
void work() {
    int n, m;
    int ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        yc[i][0] = 1;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            yc[j][i] += yc[j][i - 1];
            yc[j][j] %= mod;
        }
    }
    for (int i = 1; i <= n; i++) {
        ans += yc[n - i + 1][m] * (yc[i][m] - yc[i - 1][m]);
        ans %= mod;
    }
    cout << ans << endl;
}
} // namespace Qaaxaap
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Qaaxaap::work(), 0;
}
