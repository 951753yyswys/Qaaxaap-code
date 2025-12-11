#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        if (s.front() == s.back()) {
            cout << 0 << endl;
            continue;
        }
        bool suc = false;
        for (int j = 0; j < s.size() - 1; ++j) {
            if (s[j] == s[j + 1]) {
                cout << j + 1 << endl;
                suc = true;
                break;
            }
        }
        if (!suc)
            cout << -1 << endl;
    }
}