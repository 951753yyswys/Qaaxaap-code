#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap {
const int mod = 1e9 + 7;
int dp[55][55][55][55];
int col[55], pow[55];
void work() {
    int n, p;
    pow[0] = 1;
    for (int i = 1; i <= 50; i++) {
        pow[i] = pow[i - 1] << 1;
        pow[i] %= mod;
    }
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> col[i];
    }
    int ans = 0;
    if (col[1] == 1 || col[1] == -1) {
        dp[1][1][0][0] = 1;
        if (p == 1 && n == 1) {
            ans++;
        }
    }
    if (col[1] == 0 || col[1] == -1) {
        dp[1][0][1][0] = 1;
        if (p == 1 && n == 1) {
            ans++;
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; j + k <= i; k++) {
                for (int l = 0; j + k + l <= i; l++) {
                    int m = i - j - k - l;
                    if (col[i] == 1 || col[i] == -1) {
                        int sum = 0;
                        if (j) {
                            if (k) {
                                sum += dp[i - 1][j - 1][k][l] * pow[k - 1];
                            } else {
                                sum += dp[i - 1][j - 1][k][l];
                            }
                            sum %= mod;
                        }
                        if (l) {
                            if (k) {
                                sum += dp[i - 1][j][k][l - 1] * pow[k - 1];
                            }
                            sum %= mod;
                        }
                        if (k != i) {
                            sum *= pow[j + l + m - 1];
                        }
                        sum %= mod;
                        dp[i][j][k][l] = sum;
                    }
                    if (col[i] == 0 || col[i] == -1) {
                        int sum = 0;
                        if (k) {
                            if (j) {
                                sum += dp[i - 1][j][k - 1][l] * pow[j - 1];
                            } else {
                                sum += dp[i - 1][j][k - 1][l];
                            }
                            sum %= mod;
                        }
                        if (m) {
                            if (j) {
                                sum += dp[i - 1][j][k][l] * pow[j - 1];
                            }
                            sum %= mod;
                        }
                        if (j != i) {
                            sum *= pow[k + l + m - 1];
                        }
                        sum %= mod;
                        dp[i][j][k][l] += sum;
                        dp[i][j][k][l] %= mod;
                    }
                    if (i == n) {
                        if ((j + k) % 2 == p) {
                            ans += dp[i][j][k][l];
                            ans %= mod;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
} // namespace Qaaxaap
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Qaaxaap::work(), 0;
}
