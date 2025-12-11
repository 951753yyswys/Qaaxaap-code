#include <bits/stdc++.h>
using namespace std;
namespace Qaaxaap {
    inline void work() {
        int x1, x2, x3, y1, y2, y3;
        cin >> x1 >> x2 >> x3 >> y1 >> y2 >> y3;
        int sum = x1 * y1 + x2 * y2 + x3 * y3;
        if ( !sum )
            cout << "Orthogonal";
        else
            cout << "Non-Orthogonal";
    }
} // namespace Qaaxaap
int main() {
    return Qaaxaap::work(), 0;
}