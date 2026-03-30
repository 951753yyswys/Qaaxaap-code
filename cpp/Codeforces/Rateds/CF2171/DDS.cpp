#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        
        vector<int> pos(n+1);
        for (int i = 0; i < n; i++) {
            pos[p[i]] = i;
        }
        
        set<pair<int, int>> S_value;
        set<pair<int, int>> S_pos;
        for (int i = 2; i <= n; i++) {
            S_value.insert({i, pos[i]});
            S_pos.insert({pos[i], i});
        }
        
        vector<int> parent(n+1, -1);
        queue<int> Q;
        Q.push(1);
        parent[1] = 0;
        
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            int v_val = v;
            int v_pos = pos[v];
            
            auto it1 = S_value.lower_bound({v_val + 1, 0});
            while (it1 != S_value.end()) {
                int u_val = it1->first;
                int u_pos = it1->second;
                if (u_pos > v_pos) {
                    parent[u_val] = v;
                    Q.push(u_val);
                    it1 = S_value.erase(it1);
                    S_pos.erase({u_pos, u_val});
                } else {
                    it1++;
                }
            }
            
            auto it2 = S_pos.begin();
            while (it2 != S_pos.end() && it2->first < v_pos) {
                int u_val = it2->second;
                int u_pos = it2->first;
                if (u_val < v_val) {
                    parent[u_val] = v;
                    Q.push(u_val);
                    it2 = S_pos.erase(it2);
                    S_value.erase({u_val, u_pos});
                } else {
                    it2++;
                }
            }
        }
        
        if (S_value.empty()) {
            cout << "Yes\n";
            // for (int i = 2; i <= n; i++) {
            //     cout << parent[i] << " " << i << "\n";
            // }
        } else {
            cout << "No\n";
        }
    }
    return 0;
}