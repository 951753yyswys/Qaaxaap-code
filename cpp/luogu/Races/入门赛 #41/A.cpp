#include <bits/stdc++.h>
using namespace std;
namespace Qaaxaap {
    inline void work() {
        int n, m, r, c;
        cin >> n >> m >> r >> c;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int lx = 0, ly = 0;
        for ( int i = 0; i < n; i += r ) {
            int j = i + r - 1;
            if ( x1 <= j && x2 >= i )
                lx++;
        }
        for ( int i = 0; i < m; i += c ) {
            int j = i + c - 1;
            if ( y1 <= j && y2 >= i )
                ly++;
        }
        cout << lx * ly;
    }
} // namespace Qaaxaap
int main() {
    return Qaaxaap::work(), 0;
}