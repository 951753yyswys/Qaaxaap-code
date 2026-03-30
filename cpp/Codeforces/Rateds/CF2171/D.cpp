/***********************************************
 * If you are looking my code,have a good day! *
 * I hope you can get better rating!           *
 * Thank you hacking me!                       *
 ***********************************************/
#include <iostream>
#include <vector>
#include <algorithm>
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
        vector < int > p( n );
        for ( int i = 0; i < n; i++ ) cin >> p[ i ];
        int pos1 = find( p.begin() , p.end() , 1 ) - p.begin();
        int pos2 = find( p.begin() , p.end() , 2 ) - p.begin();
        int posn = find( p.begin() , p.end() , n ) - p.begin();
        
        if (pos1 < pos2 && posn < pos1 || pos2 < pos1 && posn < pos2) 
            cout << "No" << endl ;
        else 
            cout << "Yes" << endl ;
    } 
};
using namespace hacked;
int main() {
    func();
    return 0;
}