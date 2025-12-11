#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int ttt;
int n, a;
int p[300005];

void solve(){
	cin >> n >> a;
	for(int i=1;i<=n;++i){
		cin >> p[i];
	}
	int pos = 1;
	while(a > p[pos] && pos <= n)pos++;
	if(p[pos] == a){
		if(pos - 1 >= n - pos)cout << a - 1 << endl;
		else cout << a + 1 << endl;
	}
	else{
		if(pos - 1 >= n - pos + 1)cout << a - 1 << endl;
		else cout << a + 1 << endl;
	}
}

int main(){
	cin >> ttt;
	while(ttt--){
		solve();
	}
	return 0;
} 