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
        vector < ll > a( n + 1 );
        for ( int i = 1 ; i <= n ; i++ ) {
            cin >> a[ i ];
            if ( i == 1 || i == n ) continue;
            if ( a[ i ] == -1 ) a[i] = 0;
        }
        ll ans = 0;
        if( a[ 1 ] == -1 ) a[ 1 ] = a[ n ];
        if( a[ n ] == -1 ) a[ n ] = a[ 1 ];
        if( a[ 1 ] == -1 ) a[ 1 ] = a[ n ] = 0;
        ans = abs( a[ 1 ] - a[ n ] );
        cout << ans << endl;
        for( int i = 1 ; i <= n ; i++ ) {
            cout << a[ i ] << ' ' ;
        } 
        cout << endl ;
    } 
};
using namespace hacked;
int main() {
    func();
    return 0;
}