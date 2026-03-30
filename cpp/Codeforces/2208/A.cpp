#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace Liminal {
void work() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> cnt(n * n + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int tmp;
                cin >> tmp;
                cnt[tmp]++;
            }
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        if (mx <= (n - 1) * (n - 1) + 1) {
            cout << "YES" << endl;
        } else
            cout << "NO" << endl;
    }
}
} // namespace Liminal
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Liminal::work(), 0;
}
