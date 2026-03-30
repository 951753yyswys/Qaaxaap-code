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
    const int M = 2e5 + 10;
    vector< ll > ans( M );
    inline void func() {
        int t;
        for ( int i = 0; i <= 2e5; i++ ) {
            int d = i / 12;
            int bc = d * 12;
            int w = i % 12;
            if ( w == 0 )
                ans[ i ] = 3;
            if ( w == 1 )
                ans[ i ] = 5;
            if ( w == 2 )
                ans[ i ] = 6;
            if ( w == 3 )
                ans[ i ] = 4;
            if ( w == 4 )
                ans[ i ] = 1;
            if ( w == 5 )
                ans[ i ] = 2;
            if ( w == 6 )
                ans[ i ] = 8;
            if ( w == 7 )
                ans[ i ] = 7;
            if ( w == 8 )
                ans[ i ] = 10;
            if ( w == 9 )
                ans[ i ] = 12;
            if ( w == 10 )
                ans[ i ] = 11;
            if ( w == 11 )
                ans[ i ] = 9;
            ans[ i ] += bc;
        }
        cin >> t;
        while ( t-- )
            solve();
        return;
    }
    inline void solve() {
        int n;
        cin >> n;
        for ( int i = 0; i < n / 6 * 6; i++ )
            cout << ans[ i ] << ' ';
        for ( int i = n / 6 * 6; i < n; i++ )
            cout << i + 1 << ' ';
        cout << endl;
    }
};
using namespace hacked;
int main() {
    func();
    return 0;
}