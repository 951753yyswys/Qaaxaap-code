#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        cout << "? 1 " << n << "\n";
        cout.flush();

        long long S;
        cin >> S;
        if (S == -1) return 0;

        long long ans = 1;
        for (int k = 0; k <= 30; k++) {
            long long mod = S & ((1LL << (k + 1)) - 1);
            if (mod >= (1LL << k)) {
                ans = 1LL << k;
            }
        }

        cout << "! " << ans << "\n";
        cout.flush();
    }
    return 0;
}

