#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap {
int dp[20][183][183], t[20];
int len = 0, now;
int dfs(int pos, int sum, int mod, bool full) {
    if (pos > len) {
        return bool(sum == 0 && mod == now);
    }
    if (dp[pos][mod][sum] != -1 && !full) {
        return dp[pos][mod][sum];
    }
    int ret = 0, mx = 0;
    if (full) {
        mx = t[len - pos + 1];
    } else {
        mx = 9;
    }
    for (int i = 0; i <= mx; i++) {
        ret += dfs(pos + 1, (sum * 10 + i) % now, mod + i, full && (i == mx));
    }
    if (!full) {
        dp[pos][mod][sum] = ret;
    }
    return ret;
}
int num(int x) {
    len = 0;
    while (x) {
        t[++len] = x % 10;
        x /= 10;
    }
    int ret = 0;
    for (now = 1; now <= len * 9; now++) {
        memset(dp, -1, sizeof dp);
        ret += dfs(1, 0, 0, 1);
    }
    return ret;
}
void work() {
    int a, b;
    cin >> a >> b;
    cout << num(b) - num(a - 1);
}
} // namespace Qaaxaap
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Qaaxaap::work(), 0;
}
