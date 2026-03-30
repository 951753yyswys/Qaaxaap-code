#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap {
    void work() {
        int t;
        cin >> t;
        while (t--) {
            int n, m;
            cin >> n >> m;
            vector<vector<int>> g(n + 2, vector<int>(m + 2));
            vector<vector<int>> mx(n + 2, vector<int>(m + 2));
            vector<vector<int>> mi(n + 2, vector<int>(m + 2));
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++) {
                    cin >> g[i][j];
                    if (i == 1)
                        mx[i][j] = mi[i][j] = mi[i][j - 1] + g[i][j];
                    if (j == 1)
                        mx[i][j] = mi[i][j] = mi[i - 1][j] + g[i][j];
                }
            if ((n + m) % 2 == 0) {
                cout << "NO" << endl;
                continue;
            }
            for (int i = 2; i <= n; i++)
                for (int j = 2; j <= m; j++) {
                    mi[i][j] = g[i][j] + min(mi[i - 1][j], mi[i][j - 1]);
                    mx[i][j] = g[i][j] + max(mx[i - 1][j], mx[i][j - 1]);
                }
            // cout << "mx:" << mx[n][m] << endl << "mi:" << mi[n][m] << endl;
            if (mi[n][m] <= 0 && mx[n][m] >= 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
} // namespace Qaaxaap
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Qaaxaap::work(), 0;
}
