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
        string s;
        cin >> s;
        s = '+' + s;
        int cn = 0, cm = 0;
        for (int i = 1; i <= n - 3; i++) {
            if (s[i] == '2' && s[i + 1] == '0' && s[i + 2] == '2') {
                if (s[i + 3] == '5')
                    cn++;
                if (s[i + 3] == '6')
                    cm++;
            }
        }
        if (cm > 0)
            cout << 0 << endl;
        else if (cn == 0)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
}
} // namespace Qaaxaap
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Qaaxaap::work(), 0;
}
