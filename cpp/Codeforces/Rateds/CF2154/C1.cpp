#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int MAX_VAL = 200001;
vector<int> mipri(MAX_VAL + 1);
vector<int> pris;
void pre() {
    for (int i = 2; i <= MAX_VAL; i++) {
        if (mipri[i] == 0) {
            mipri[i] = i;
            pris.push_back(i);
        }
        for (int j = 0; j < pris.size(); j++) {
            int p = pris[j];
            if (p * i > MAX_VAL) break;
            mipri[i * p] = p;
            if (i % p == 0) break;
        }
    }
}
vector<int> fpris(int n) {
    vector<int> yk;
    if (n == 1) return yk;
    int temp = n;
    while (temp > 1) {
        int p = mipri[temp];
        yk.push_back(p);
        while (temp % p == 0) temp /= p;
    }
    return yk;
}
signed main() {
    pre();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];
        vector<int> b(n);
        for (int i = 0; i < n; i++) 
            cin >> b[i];
        vector<bool> hp(MAX_VAL + 1, false);
        bool cost0 = 0;
        for (int i = 0; i < n; i++) {
            vector<int> yk = fpris(a[i]);
            for (int p : yk) {
                if (hp[p]) {
                    cost0 = 1;
                    break;
                }
                hp[p] = 1;
            }
            if (cost0) break;
        }
        if (cost0) {
            cout << 0 << endl;
            continue;
        }
        bool cost1 = 0;
        for (int i = 0; i < n; i++) {
            int x = a[i] + 1;
            vector<int> yk = fpris(x);
            for (int p : yk) {
                if (p <= MAX_VAL && hp[p]) {
                    cost1 = 1;
                    break;
                }
            }
            if (cost1) break;
        }
        if (cost1) 
            cout << 1 << endl;
        else 
            cout << 2 << endl;
    }
    return 0;
}