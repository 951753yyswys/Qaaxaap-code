#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap {
const int MXC = 2e5, MXN = 1010;
int f[MXC], c[5], d[5];
void pre() {
    f[0] = 1;
    for (int i = 1; i < 5; i++) {
        for (int j = 0; j <= 1e5; j++) {
            f[j + c[i]] += f[j];
        }
    }
}
int dfs(int id, int ed, bool flag) {
    int ret = 0;
    if (ed < 0) {
        return 0;
    }
    if (id > 4) {
        return f[ed] * (flag ? 1 : -1);
    }
    ret += dfs(id + 1, ed, flag);
    ret += dfs(id + 1, ed - (d[id] + 1) * c[id], flag ^ 1);
    return ret;
}
void work() {
    for (int i = 1; i < 5; i++) {
        cin >> c[i];
    }
    pre();
    int t;
    cin >> t;
    while (t--) {
        for (int i = 1; i < 5; i++) {
            cin >> d[i];
        }
        int s;
        cin >> s;
        cout << dfs(1, s, 1) << endl;
    }
}
} // namespace Qaaxaap
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Qaaxaap::work(), 0;
}

