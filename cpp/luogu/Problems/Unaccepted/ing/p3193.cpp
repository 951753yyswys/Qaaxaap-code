#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M_SIZE = 25;
int mod;
namespace DS {
template <typename T> class Matrix {
public:
    vector<vector<T>> mt;
    Matrix() : mt(M_SIZE, vector<T>(M_SIZE, T{})) {};
    void init(T one) {
        for (int i = 0; i < M_SIZE; i++) {
            mt[i][i] = one;
        }
    }
};
template <typename T>
Matrix<T> operator*(const Matrix<T> &l, const Matrix<T> &r) {
    Matrix<T> ret;
    for (int i = 0; i < M_SIZE; i++) {
        for (int j = 0; j < M_SIZE; j++) {
            ret.mt[i][j] = 0;
            for (int k = 0; k < M_SIZE; k++) {
                ret.mt[i][j] = l.mt[i][k] * r.mt[k][j];
                ret.mt[i][j] %= mod;
            }
        }
    }
    return ret;
}
} // namespace DS
namespace Qaaxaap {
template <typename T> T qpow(T d, int z) {
    T t = T{};
    if (!z) {
        return t;
    }
    z--;
    while (z) {
        if (z & 1) {
            t *= d;
        }
        d *= d;
        z >>= 1;
    }
    return t;
}
void work() {}
} // namespace Qaaxaap
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Qaaxaap::work(), 0;
}
