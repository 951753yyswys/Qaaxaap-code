#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap {
const double eps = 5e-6;
void work() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, bool> ap;
    for (auto &tmp : a) {
        cin >> tmp;
        ap[tmp] = 1;
    }
    sort(a.begin(), a.end());
    double ans = -1;
    for (double i = a[0] + 1;; i -= eps) {
        int ed = 0;
        int lst = -1;
        for (int j = 1; ed != -1 && ceil(i * j) - 1 <= a[n - 1]; j++) {
            int now = ceil(i * j) - 1;
            if (now == lst) {
                continue;
            }
            lst = now;
            if (a[ed] != now) {
                if (ed < n - 1 && a[ed + 1] == now) {
                    ed = -1;
                }
            }
            while (a[ed] == now) {
                ed++;
            }
        }
        if (ed == n) {
            ans = i;
            break;
        }
    }
    cout << fixed << setprecision(5) << ans << endl;
}
} // namespace Qaaxaap
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Qaaxaap::work(), 0;
}
