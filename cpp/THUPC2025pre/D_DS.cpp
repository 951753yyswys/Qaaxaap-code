#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long solve() {
    int n;
    cin >> n;
    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x.rbegin(), x.rend()); // 降序
    
    long long ans = 0;
    
    // 枚举左边个数l和右边个数r
    for (int l = 0; l <= n; l++) {
        for (int r = 0; l + r <= n; r++) {
            int m = n - l - r;
            
            // 构造排列a[1..n]
            vector<long long> a(n + 1); // 1-indexed
            
            // 左边：位置1..l，放最大的l个数
            for (int i = 1; i <= l; i++) {
                a[i] = x[i - 1];
            }
            
            // 中间：位置l+1..l+m，放接下来的m个数
            for (int i = 1; i <= m; i++) {
                a[l + i] = x[l + i - 1];
            }
            
            // 右边：位置l+m+1..n，放最后的r个数（逆序，大的放右边）
            for (int i = 1; i <= r; i++) {
                a[n - i + 1] = x[l + m + i - 1];
            }
            
            // 计算分数 O(n)
            vector<long long> pref(n + 1, 0), pref2(n + 1, 0);
            for (int i = 1; i <= n; i++) {
                pref[i] = pref[i - 1] + a[i];
                pref2[i] = pref2[i - 1] + i * a[i];
            }
            
            long long score = 0;
            for (int i = 1; i <= n; i++) {
                score += a[i] * (i * (pref[n] - pref[i]) - (pref2[n] - pref2[i]));
            }
            
            ans = max(ans, score);
        }
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    
    return 0;
}