#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap {
const int mod = 998244353;
int fac[101010];
int qp(int d, int z) {
    int t = 1;
    while (z) {
        if (z & 1) {
            t *= d;
            t %= mod;
        }
        d *= d;
        d %= mod;
        z >>= 1;
    }
    return t;
}
int C(int n, int m) {
    return fac[n] * qp(fac[m] * fac[n - m] % mod, mod - 2) % mod;
}
void work() {
    int t;
    cin >> t;
    fac[0] = 1;
    for (int i = 1; i <= 101000; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt0 = 0, cnt11 = 0;
        s += '+';
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1' && s[i + 1] == '1') {
                cnt11++;
                i++;
            }
            if (s[i] == '0') {
                cnt0++;
            }
        }
        // cout << endl << ' ' << cnt1 << ' ' << cnt11 << endl;
        cout << flush << C(cnt0 + cnt11, cnt0) << endl;
    }
}
} // namespace Qaaxaap
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Qaaxaap::work(), 0;
}
