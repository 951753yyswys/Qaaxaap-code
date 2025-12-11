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
        vector< ll > a( n );
        for ( auto& tmp : a )
            cin >> tmp;
        for ( int i = 0; i < n - 2; i++ )
            a[ n - 2 ] -= a[ i ];
        a[ n - 1 ] -= a[ n - 2 ];
        cout << a[ n - 1 ] << endl;
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