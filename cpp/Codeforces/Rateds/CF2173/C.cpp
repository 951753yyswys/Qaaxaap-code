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
#include <queue>
using namespace std;
#define int long long
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
        int n, k;
        cin >> n >> k;
        vector< int > a( n ), b;
        map< int, int > mp;
        for ( auto& tmp : a )
            cin >> tmp, mp[ tmp ] = 1;
        set< int > qu;
        for ( auto tmp : a )
            qu.insert( tmp );
        bool flag = 1;
        while ( !qu.empty() ) {
            queue< int > del;
            auto ed = qu.begin();
            int hd = *ed, po = 1;
            while ( ed != qu.end() ) {
                del.push( *ed );
                po++;
                ed = qu.lower_bound( hd * po );
                while ( ed != qu.end() && *ed != po * hd )
                    po++, ed = qu.lower_bound( po * hd );
            }
            while ( !del.empty() )
                qu.erase( del.front() ), del.pop();
            b.push_back( hd );
        }
        for ( auto tmp : b ) 
            for ( int i = 1; i * tmp <= k; i++ )
                if ( mp[ i * tmp ] != 1 )
                    flag = 0;
        if ( flag == 0 ) {
            cout << -1 << endl;
            return;
        }
        cout << b.size() << endl;
        for ( auto tmp : b )
            cout << tmp << ' ';
        cout << endl;
    }
}
using namespace hacked;
signed main() {
    ios::sync_with_stdio( false );
    cin.tie( nullptr );
    cout.tie( nullptr );
    func();
    return 0;
}