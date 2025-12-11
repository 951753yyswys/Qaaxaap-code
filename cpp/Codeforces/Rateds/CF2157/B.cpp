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
        int n, x, y;
        cin >> n >> x >> y;
        string s;
        cin >> s;
        int cnt4 = 0, cnt8 = 0;
        for ( int i = 0; i < s.size(); i++ ) {
            if ( s[ i ] == '4' )
                cnt4++;
            else
                cnt8++;
        }
        if ( abs( x ) + abs( y ) <= cnt4 + cnt8 * 2 && abs( x ) <= cnt4 + cnt8 && abs( y ) <= cnt4 + cnt8 )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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