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
        int n, l, r;
        cin >> n >> l >> r;
        vector< ll > a( n );
        for ( int i = 0; i < n; i++ ) 
            cin >> a[ i ];
        sort( a.begin(), a.end() );
        vector< ll > pre( n + 1 );
        vector< ll > suf( n + 1 );
        for ( int i = 0; i < n; i++ ) 
            pre[ i + 1 ] = pre[ i ] + a[ i ];
        for ( int i = 0; i < n; i++ ) 
            suf[ i + 1 ] = suf[ i ] + a[ n - 1 - i ];
        ll ans = 0;
        for ( int b = -n; b <= n; b++ ) {
            int low = max( 0, -b );
            int high = ( n - b ) / 2;
            if ( low > high )
                continue;
            ll best = -1e18;
            if ( high - low + 1 <= 10 ) 
                for ( int i = low; i <= high; i++ ) 
                    best = max( best, suf[ i ] - pre[ i + b ] );
            else {
                int lt = low, rt = high;
                while ( rt - lt > 2 ) {
                    int mid1 = lt + ( rt - lt ) / 3;
                    int mid2 = rt - ( rt - lt ) / 3;
                    ll val1 = suf[ mid1 ] - pre[ mid1 + b ];
                    ll val2 = suf[ mid2 ] - pre[ mid2 + b ];
                    if ( val1 < val2 ) 
                        lt = mid1;
                    else 
                        rt = mid2;
                }
                for ( int i = lt; i <= rt; i++ ) 
                    best = max( best, suf[ i ] - pre[ i + b ] );
            }
            ll cur = min( best + (ll)b * l, best + (ll)b * r );
            if ( cur > ans ) 
                ans = cur;
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