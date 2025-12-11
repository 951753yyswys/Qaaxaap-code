/***********************************************
 * If you are looking my code,have a good day! *
 * I hope you can get better rating!           *
 * Thank you hacking me!                       *
 ***********************************************/
#include <iostream>
#include <vector>
#include <memory>
using namespace std;
namespace hacked {
    using ll = long long;
    inline void solve();
    inline void func() {
        int t;
        cin >> t;
        while ( t-- )
            solve();
        return;
    }
    inline void solve() {
        int n;
        cin >> n;
        if ( n % 2 ) {
            cout << 0 << endl;
            return;
        }
        n >>= 1;
        int ans = 1;
        ans += ( n >> 1 );
        cout << ans << endl;
    } 
};
using namespace hacked;
int main() {
    func();
    return 0;
}