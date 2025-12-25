#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{



	freopen("ch.in","r",stdin);
	int ch=clock();
	int t;
	cin>>t;
    for(int t1=0;t1<t;t1++)
    {
    int n ; cin >> n ;
    vector<int> v(n) ;
    for (int i = 0 ; i <n  ; ++i) cin >> v[i] ;
    sort(v.begin(), v.end()) ;
    int gauche = 1 , droite = 1e9 +1 , mid , result = 1 ;
    while(gauche <= droite) {
        mid = (gauche + droite) / 2 ;
        // cout << "mid "<< mid << endl ;
        bool test = true;
        set<int> e ;
        int ind = n ;
        for (int i = 0 ; i < n ; ++i) {
            if(v[i]<mid) e.insert (v[i]) ;
            else {ind = i ; break ;}
        }
        set<int> f ;
        for (int i = ind ; i < n ; ++i) {
            f.insert (v[i]) ;
        }
        if(e.size()>1) test = false ;
        if(e.size() ==1) {
            for (auto it : f) {
                if( ((it - v[0] )) < mid ) { test = 0 ; }
            }
        }
        e.clear(); f.clear() ;
        if(test) {
            result = mid ;
            gauche= mid +1;
        }
        else {
            droite = mid -1 ;
        }

    }
    cout << result << endl ;






}	cout<<clock()-ch;

    return 0;
}
