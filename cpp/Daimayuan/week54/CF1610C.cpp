#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace Qaaxaap {
    void work() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            vector<int> a(n + 1), b(n + 1);
            for (int i = 1; i <= n; i++)
                cin >> a[i] >> b[i];
            int ans = 0, l = 0, r = n;
            auto check = [&](int x) -> bool {
                int cnt = 0;
                for (int i = 1; i <= n; i++)
                    if (cnt <= b[i] && x - cnt - 1 <= a[i])
                        cnt++;
                return cnt >= x;
            };
            while (l <= r) {
                int mid = l + r >> 1;
                if (check(mid)) {
                    ans = mid;
                    l = mid + 1;
                } else
                    r = mid - 1;
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
