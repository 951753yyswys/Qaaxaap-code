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
#include <climits>
using namespace std;
namespace hacked {
    using ll = long long;
    const int INF = INT_MAX;
    const int L = 62;
    const int smax = L + 2;
    inline void solve();
    inline void func() {
        int t;
        cin >> t;
        while ( t-- )
            solve();
    }
    inline void solve() {
        ll n, k;
        cin >> n >> k;
        int p0 = __builtin_popcountll( n );
        vector< vector< int > > dp( 2, vector< int >( smax, INF ) );
        dp[ 0 ][ 0 ] = 0;
        for ( int i = 0; i < L; i++ ) {
            vector< vector< int > > ndp( 2, vector< int >( smax, INF ) );
            int ni = ( n >> i ) & 1LL;
            for ( int c = 0; c <= 1; c++ ) {
                for ( int s = 0; s < smax; s++ ) {
                    int now = dp[ c ][ s ];
                    if ( now >= INF )
                        continue;
                    for ( int mi = 0; mi <= 1; mi++ ) {
                        int t = ni + mi + c;
                        int b = t & 1;
                        int nc = ( t >> 1 );
                        int ns = s + b;
                        if ( ns >= smax )
                            continue;
                        int nm = now + mi;
                        ndp[ nc ][ ns ] = min( ndp[ nc ][ ns ], nm );
                    }
                }
            }
            dp = move( ndp );
        }
        ll bst = (ll)4e18;
        for ( int s = 0; s < smax; s++ ) {
            for ( int c = 0; c <= 1; c++ ) {
                int nd = dp[ c ][ s ];
                if ( nd <= k ) {
                    ll pf = s + c;
                    bst = min( bst, pf );
                }
            }
        }
        ll ans = (ll)p0 + k - bst;
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