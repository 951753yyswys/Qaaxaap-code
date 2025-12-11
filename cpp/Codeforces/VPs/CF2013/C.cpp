#include <bits/stdc++.h>
#define int long long
#define sor( i, l, r ) for ( int i = l; i <= r; ++i )
#define ros( i, r, l ) for ( int i = r; i >= l; --i )
using namespace std;
namespace Revitalize {
    constexpr const int N = 5e5 + 5, P = 998244353;
    int T, n;
    inline void work() {
        cin >> T;
        while ( T-- ) {
            cin >> n;
            string s;
            while ( s.size() < n ) {
                cout << "? " << s + "1" << endl;
                int ans;
                cin >> ans;
                if ( !ans && s.empty() ) {
                    sor( i, 1, n ) s += '0';
                    cout << "! " << s << endl;
                    break;
                }
                if ( !ans ) {
                    cout << "? " << s + "0" << endl;
                    int ans2;
                    cin >> ans2;
                    if ( !ans2 )
                        break;
                    else
                        s += '0';
                } else
                    s += '1';
                if ( s.size() == n )
                    cout << "! " << s << endl;
            }
            if ( s.size() == n )
                continue;
            while ( s.size() < n ) {
                cout << "? " << "1" + s << endl;
                int ans;
                cin >> ans;
                if ( !ans )
                    s = "0" + s;
                else
                    s = '1' + s;
                if ( s.size() == n )
                    cout << "! " << s << endl;
            }
        }
    }
}
signed main() {
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    ios::sync_with_stdio( false );
    cin.tie( 0 );
    cout.tie( 0 );
    return Revitalize::work(), 0;
}