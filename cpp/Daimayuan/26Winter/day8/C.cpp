#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace DS {
class fenwick {
public:
    vector<int> t;
    int n;
    fenwick(int n) : t(n + 1), n(n) {}
    int lowbit(int x) {
        return x & (-x);
    }
    void add(int pl,int val) {
        while (pl <= n) {
            t[pl] += val;
            pl += lowbit(pl);
        }
    }
    int ask(int pl) {
        int ret = 0;
        while (pl) {
            ret += t[pl];
            pl -= lowbit(pl);
        }
        return ret;
    }
    int ask(int l, int r) {
        return ask(r) - ask(l - 1);
    }
};
}
using namespace DS;
namespace Qaaxaap {
void work() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<vector<int>> sum(9, vector<int>(n+1));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[a[i]][i]++;
        }
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] += sum[i][j-1];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 2; j <= n; j++) {
                vector<int> cnt(9);
                for (int k = 1; k <= 8; k++) {
                    cnt[k] = sum[k][j] - sum[k][i - 1];
                    cnt[k] %= 3;
                }
                for (int k = 1; k <= 6; k++) {
                    if (cnt[k] && cnt[k + 1] && cnt[k + 2]) {
                        int mx = min({cnt[k], cnt[k + 1], cnt[k + 2]});
                        cnt[k] -= mx;
                        cnt[k + 1] -= mx;
                        cnt[k + 2] -= mx;
                    }
                }
                int flag = *max_element(cnt.begin(), cnt.end());
                if (!flag) {
                    ans++;
                }
            }
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