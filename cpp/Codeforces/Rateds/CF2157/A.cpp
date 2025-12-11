/***********************************************
 * If you are looking my code,have a good day! *
 * I hope you can get better rating!           *
 * Thank you hacking me!                       *
 ***********************************************/
#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
using namespace std;
namespace hacked {
    using ll = long long;
    inline void solve();
    inline void func() {
        int t;
        cin >> t;
        while ( t-- )
            solve();
    }
    inline void solve() {
        int n;
        cin >> n;
        vector< int > a( n ), cnt( n + 1 );
        for ( int i = 0; i < n; i++ ) {
            int l;
            cin >> l;
            cnt[ l ]++;
        }
        int ans = 0;
        for ( int i = 0; i <= n; i++ ) {
            if ( cnt[ i ] < i )
                ans += cnt[ i ];
            else
                ans += cnt[ i ] - i;
        }
        cout << ans << endl;
    }
}
using namespace hacked;
int main() {
    ios::sync_with_stdio( false );
    cin.tie( nullptr );
    cout.tie( nullptr );
    func();
    return 0;
}