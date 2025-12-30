#include<bits/stdc++.h>
using namespace std;
 
//#pragma GCC optimize("O3","unroll-loops")
//#pragma GCC target("avx,bmi,bmi2,lzcnt,popcnt")
 
// PBDS Template
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <class T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
//using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
// Preset
//const int maxn = 200000;
//const int INF = 2e9;
//const long long int LINF = 5e18;
//const long long int mod = 1e9 + 7;
//const long long int mod2 = 998244353;
//const double e = 2.71828;
//const double PI = acos(-1);
//const double eps = 1e-9;
#define pb push_back
#define ll long long 
//#define int long long
//#define ull unsigned long long
//#define ld double
//#define all(x) x.begin(), x.end()
//typedef pair<char,char> pc;
//typedef pair<double,double> pdb;
//typedef pair<int,int> pi;
//typedef pair<ll,ll> pll;
//typedef pair<pi,int> pii;
//typedef pair<int,ll> pil;
//typedef pair<ll,int> pli;
//typedef pair<string,int> psi;
//typedef pair<int,string> pis;
//typedef pair<char,int> pci;
//typedef pair<int,char> pic;
//typedef pair<int,double> pid;
//typedef pair<double,int> pdi;
//int dr[4] = {0,1,0,-1}, dc[4] = {1,0,-1,0};

vector<vector<int>> ab,bc;

void solve() {
	int n;
	cin >> n;
	ab.resize(2*n+5);
	bc.resize(2*n+5);
	for (int i=1; i<2*n+5; i++) {
		ab[i].assign(n+5,0);
		bc[i].assign(n+5,0);
	}
	int a[3*n+5], b[3*n+5], c[3*n+5];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		a[i+n] = a[i];
		a[i+2*n] = a[i];
	}
	for (int i=1; i<=n; i++) {
		cin >> b[i];
		b[i+n] = b[i];
		b[i+2*n] = b[i];
	}
	for (int i=1; i<=n; i++) {
		cin >> c[i];
		c[i+n] = c[i];
		c[i+2*n] = c[i];
	}
	for (int i=2*n; i>=1; i--) {
		for (int j=0; j<n; j++) {
			if (a[i] < b[i+j]) ab[i][j]++;
			if (b[i] < c[i+j]) bc[i][j]++;
			if (ab[i][j]) ab[i][j] += ab[i+1][j];
			else ab[i][j] = 0;
			if (bc[i][j]) bc[i][j] += bc[i+1][j];
			else bc[i][j] = 0;
		}
	}
//	cout << "test" << endl;
//	for (int i=1; i<=2*n; i++) {
//		for (int j=0; j<n; j++) cout << bc[i][j] << ' ';
//		cout << '\n';
//	}
	int res[n+5];
	memset(res,0,sizeof(res));
	for (int i=1; i<=n; i++) {
		for (int j=0; j<n; j++) {
			if (bc[i][j] >= n) res[i]++;
		}
//		cout << res[i] << ' ';
	}
//	cout << '\n';
	ll ans = 0;
	for (int i=1; i<=n; i++) {
		for (int j=0; j<n; j++) {
			if (ab[i][j] >= n) {
				int idx = i+j;
				if (idx > n) idx -= n;
				assert(idx <= n);
				ans += 1ll*res[idx];
//				cout << i << ' ' << j << ' ' << res[idx] << '\n';
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	freopen("fh.in","r",stdin);
	int cl=clock();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	precompute();
//	FFT::init_fft();
    int tc = 1;
	cin >> tc;
//	getchar();
//	int idx = 1;
	while (tc--) solve();
	cout<<clock()-cl;
    return 0;
}
