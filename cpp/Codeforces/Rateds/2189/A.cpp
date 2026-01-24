#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap {
    void work() {
        int t;
        cin >> t;
        while (t--) {
            int n, h, l;
            cin >> n >> h >> l;
            vector<int> a(n);
            for (auto &tmp : a)
                cin >> tmp;
            int bt = 0, ht = 0, lt = 0;
            for (auto tmp : a) {
                if (tmp <= h) {
                    if (tmp <= l) {
                        bt++;
                    } else {
                        ht++;
                    }
                } else {
                    if (tmp <= l) {
                        lt++;
                    }
                }
            }
            int ans = 0;
            for (int i = n / 2; i >= 0; i--) {
                if (max(0ll, i - ht) + max(0ll, i - lt) <= bt) {
                    ans = i;
                    break;
                }
            }
            cout << ans << endl;
        }
    }
} // namespace Qaaxaap
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Qaaxaap::work(), 0;
}
