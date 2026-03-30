#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap {
const int mod = 1e9 + 7;
int dp[1010][1010];
void work() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dp[1][i] = 1;
    }
    for (int k = 2; k <= 2 * m; k++) {
        for (int i = 1; i <= n; i++) {
            dp[k][i] = 0;
            for (int j = 1; j <= i; j++) {
                dp[k][i] += dp[k - 1][j];
                dp[k][i] %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[2 * m][i];
        ans %= mod;
    }
    cout << ans;
}
} // namespace Qaaxaap
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Qaaxaap::work(), 0;
}
