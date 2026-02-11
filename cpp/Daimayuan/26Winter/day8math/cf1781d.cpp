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
        vector<int> v(n);
        for (auto &tmp : v) {
            cin >> tmp;
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = v[i];
                int b = v[j];
                int x = -1;
                for (int k = 1; k * k < b - a; k++) {
                    if ((b - a) % k) {
                        continue;
                    }
                    int pls = (b - a) / k;
                    if ((pls + k) % 2) {
                        continue;
                    }
                    int m = (pls + k) >> 1;
                    if (m == 0 || pls - m == 0) {
                        //cout << 114514 << endl;
                        //cout << m << ' ' << (pls - m) << endl;
                        continue;
                    }
                    m = max(pls - m, m);
                    x = m * m - b;
                    //cout << (pls - m) << ' ' << m << endl;
                    //cout << "x:" << x << endl;
                    //cout << "a,b:" << a << ' ' << b << endl; 
                    if (x >= 0) {
                        int lans = 0;
                        for (auto tmp : v) {
                            int sqr = sqrtl(tmp + x);
                            //cout << ' ' << sqrtl(tmp + x) << endl;
                            //cout << ' ' << sqr << endl;
                            if(sqr * sqr == tmp + x) {
                                lans++;
                            }
                        }
                        ans = max(ans, lans);     
                    }
                }
                //cout << ' ' << x << endl;
                if (x <= -1) {
                    continue;
                }
            }
        }
        int lans = 0;
        for (auto tmp : v) {
            int sqr = sqrtl(tmp);
            if (sqr * sqr == tmp) {
                lans++;
            }
        }
        cout << max(ans, lans) << endl;
    }
}
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    return Qaaxaap::work(), 0;
}