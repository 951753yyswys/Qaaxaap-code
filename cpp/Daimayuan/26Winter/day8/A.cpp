#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap {
const int N = 5e5, mod = 998244353;
int fac[N + 5],inv[N + 5];
int qp(int d, int z) {
    int t = 1;
    while (z) {
        if (z & 1) {
            t = t * d % mod;
        }
        d = d * d % mod;
        z >>= 1;
    }
    return t;
}
int p(int k,int n) {
    if(n > k) {
        return 0;
    }
    return fac[k] * inv[k - n] % mod;
}
void pre() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = qp(fac[i], mod - 2);
    }
}
void work() {
    pre();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        if (n == 1) {
        	cout << 0 << endl;
        	continue;
        }
        int ans = qp(k, n) - (n - 1) * p(k, n);
        ans += mod * 1000;
        ans %= mod;
        for (int d = 1; d <= min(n - 2, k); d++) {
            ans += p(k, d) * qp(k - d, n - d) % mod;
            ans %= mod;
        }
        cout << ans << endl;
    }
}
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Qaaxaap::work(), 0;
}