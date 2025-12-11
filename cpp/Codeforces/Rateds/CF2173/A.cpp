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
namespace hacking {
    using ll = long long;
    inline void solve();
    inline void func() {
        int t;
        cin >> t;
        while ( t-- )
            solve();
    }
    inline void solve() {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        s = '+' + s;
        for ( int i = n; i >= 1; i-- )
            if ( s[ i ] == '1' )
                for ( int j = 1; j <= k && i + j <= n; j++ )
                    s[ i + j ] = '1';
        int ans = 0;
        for ( int i = 1; i <= n; i++ )
            ans += ( s[ i ] != '1' );
        // cout << s << endl;
        cout << ans << endl;
    }
}
using namespace hacking;
int main() {
    ios::sync_with_stdio( false );
    cin.tie( nullptr );
    cout.tie( nullptr );
    func();
    return 0;
}