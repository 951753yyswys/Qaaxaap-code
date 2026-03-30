#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX_A = 200000;
vector<int> primes;
void sieve() {
    vector<bool> isp(MAX_A + 2, 1);
    isp[0] = isp[1] = 0;
    for (int i = 2; i <= MAX_A + 1; i++) {
        if (isp[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= MAX_A + 1; j += i) 
                isp[j] = 0;
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];
        for (int i = 0; i < n; i++) 
            cin >> b[i];
        int ans = 1e18;
        bool found = 0;
        unordered_map<int, int> pric;
        for (int i = 0; i < n && !found; i++) {
            int x = a[i];
            for (int p : primes) {
                if (p * p > x) break;
                if (x % p == 0) {
                    pric[p]++;
                    if (pric[p] >= 2) {
                        ans = 0;
                        found = 1;
                        break;
                    }
                    while (x % p == 0) 
                        x /= p;
                }
            }
            if (x > 1) {
                pric[x]++;
                if (pric[x] >= 2) {
                    ans = 0;
                    found = 1;
                }
            }
        }
        if (found) {
            cout << "0\n";
            continue;
        }
        unordered_set<int> wait;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            for (int p : primes) {
                if (p * p > x) break;
                if (x % p == 0) {
                    wait.insert(p);
                    while (x % p == 0) 
                        x /= p;
                }
            }
            if (x > 1) 
                wait.insert(x);
            x = a[i] + 1;
            for (int p : primes) {
                if (p * p > x) break;
                if (x % p == 0) {
                    wait.insert(p);
                    while (x % p == 0) 
                        x /= p;
                }
            }
            if (x > 1) 
                wait.insert(x);
        }
        for(int p:wait) {
            vector<int> costs;
            for (int i = 0; i < n; i++) {
                int tmp = a[i] % p;
                int cost = (tmp == 0) ? 0 : (p - tmp) * b[i];
                costs.push_back(cost);
            }
            int min1 = 1e18, min2 = 1e18;
            for (int cost : costs) {
                if (cost < min1) {
                    min2 = min1;
                    min1 = cost;
                } 
                else if (cost < min2) 
                    min2 = cost;
            }
            if (min2 < 1e18) 
                ans = min(ans, min1 + min2);
        }
        cout << ans << '\n';
    }
    return 0;
}