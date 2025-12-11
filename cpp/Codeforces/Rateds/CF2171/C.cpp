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
        int n , xoor = 0 ;
        cin >> n;
        vector < ll > a( n + 1 ) , b( n + 1 );
        for ( int i = 1 ; i <= n ; i++ ) 
            cin >> a[ i ] , xoor ^= a[ i ];
        for ( int i = 1 ; i <= n ; i++ ) 
            cin >> b[ i ] , xoor ^= b[ i ];
        if ( xoor == 0 ) {
            cout<< "Tie" << endl ;
            return;
        }
        for ( int i = n ; i >= 1 ; i-- ) {
            if ( a[ i ] != b[ i ] ) {
                if ( i % 2 ) 
                    cout << "Ajisai" << endl ;
                else 
                    cout << "Mai" << endl ;
                return;
            }
        }
    } 
};
using namespace hacked;
int main() {
    func();
    return 0;
}