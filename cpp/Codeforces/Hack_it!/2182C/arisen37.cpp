#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	freopen("fh.in","r",stdin);
	ios::sync_with_stdio(0);
	int cl=clock();
	int t; cin>>t;
	while(t--){
	    ll n ; cin>>n;
	    
	    vector<ll> a(n) , b(n) , c(n);
	    
	    for(int i = 0 ; i < n ; i++){
	        cin>>a[i];
	    }
	    
	    for(int i = 0 ; i < n ; i++){
	        cin>>b[i];
	    }
	    for(int i = 0 ; i < n ; i++){
	        cin>>c[i];
	    }
	    
	    map<ll,ll> mpp1 , mpp2;
	    
	    for(int j = 0 ; j < n ; j++){
	        for(int k = 0 ; k < n ; k++){
	           if(b[j] >= c[k]) mpp1[(j-k+n) % n] = -1; 
	        }
	    }
	    
	    for(int j = 0 ; j < n ; j++){
	        for(int k = 0 ; k < n ; k++){
	            
	           if(a[j] >= b[k]) mpp2[(j-k+n) % n] = -1; 
	        }
	    }
	    
	    ll cnt = 0;
	    
	    for(int i = 0 ; i < n ; i++){
	        for(int j = 0 ; j < n ; j++){
	            if(mpp1[i] == 0 && mpp2[j] == 0) cnt++; 
	        }
	    }
	    
	    cout << cnt*n << endl;
	}
	cerr<<clock()-cl;
}

