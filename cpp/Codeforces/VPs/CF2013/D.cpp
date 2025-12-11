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
namespace DataS {
    template < typename T >
    class Fenwick {
    private:
        vector< T > tree;
        int mx;
        inline int lowbit( int n ) {
            return n & ( -n );
        }

    public:
        Fenwick( int n ) {
            mx = n + 1;
            tree.resize( n + 2 );
        }
        inline void add( int pl, T val ) {
            while ( pl <= mx ) {
                tree[ pl ] += val;
                pl += lowbit( pl );
            }
        }
        inline T query( int pl ) {
            T ans = T{};
            while ( pl > 0 ) {
                ans += tree[ pl ];
                pl -= lowbit( pl );
            }
            return ans;
        }
    };
}
using namespace DataS;
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
        vector< ll > pre( n + 1 ), suf( n + 1 ), a( n + 1 );
        for ( int i = 1; i <= n; i++ )
            cin >> a[ i ];
        pre[ 1 ] = a[ 1 ];
        suf[ n ] = a[ n ];
        for ( int i = 2; i <= n; i++ )
            pre[ i ] = min( pre[ i - 1 ], a[ i ] );
        for ( int i = n - 1; i >= 1; i-- )
            suf[ i ] = max( suf[ i + 1 ], a[ i ] );
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