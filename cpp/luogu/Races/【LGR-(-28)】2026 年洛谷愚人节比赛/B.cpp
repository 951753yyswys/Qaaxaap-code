#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace Qaaxaap {
struct Row {
    string s;
    vector<int> nums;
    int cnt; // 数字个数
};

bool cmp(const Row &a, const Row &b) { return a.cnt < b.cnt; }

void work() {
    int n;
    cin >> n;
    cin.ignore(); // 忽略行数后的换行符
    vector<Row> rows(n);
    for (int i = 0; i < n; i++) {
        getline(cin, rows[i].s);
        // 解析当前行中的所有整数
        string &str = rows[i].s;
        int idx = 0;
        while (idx < str.size()) {
            // 跳过非数字
            while (idx < str.size() && !isdigit(str[idx]))
                idx++;
            if (idx >= str.size())
                break;
            // 解析数字
            int num = 0;
            while (idx < str.size() && isdigit(str[idx])) {
                num = num * 10 + (str[idx] - '0');
                idx++;
            }
            rows[i].nums.push_back(num);
        }
        rows[i].cnt = rows[i].nums.size();
    }

    // 按数字个数排序，确保第 i 行有 i 个数字
    sort(rows.begin(), rows.end(), cmp);

    // 验证排序后每行数字个数是否与行号一致（可选）
    for (int i = 0; i < n; i++) {
        if (rows[i].cnt != i + 1) {
            // 数据不合法，但题目保证合法，这里可以忽略
        }
    }

    // 构建 DP 数组，f[i][j] 表示第 i 行第 j 个数字（1-based）
    const int MAXN = 2000;
    static int f[MAXN][MAXN];
    memset(f, 0, sizeof(f));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            f[i][j] = rows[i - 1].nums[j - 1];
        }
    }

    // 自底向上 DP
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            f[i][j] += max(f[i + 1][j], f[i + 1][j + 1]);
        }
    }

    cout << f[1][1] << endl;
}
} // namespace Qaaxaap

signed main() {
    Qaaxaap::work();
    return 0;
}
