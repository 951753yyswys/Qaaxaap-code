#include <iostream>
#include <vector>
#include <stack>
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
        
        vector<int> pos(n + 1);
        for (int i = 0; i < n; i++) {
            pos[p[i]] = i;
        }
        
        vector<vector<int>> graph(n + 1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() < p[i]) {
                st.pop();
            }
            if (!st.empty()) {
                graph[st.top()].push_back(p[i]);
                graph[p[i]].push_back(st.top());
            }
            st.push(p[i]);
        }
        
        vector<bool> visited(n + 1, false);
        stack<int> dfs;
        dfs.push(1);
        visited[1] = true;
        int count = 1;
        while (!dfs.empty()) {
            int u = dfs.top();
            dfs.pop();
            for (int v : graph[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    count++;
                    dfs.push(v);
                }
            }
        }
        
        if (count == n) {
            cout << "Yes\n";
            if (t != 0) {
                stack<int> st2;
                vector<int> parent(n + 1, -1);
                for (int i = 0; i < n; i++) {
                    while (!st2.empty() && st2.top() < p[i]) {
                        st2.pop();
                    }
                    if (!st2.empty()) {
                        parent[p[i]] = st2.top();
                    }
                    st2.push(p[i]);
                }
                for (int i = 2; i <= n; i++) {
                    cout << parent[i] << " " << i << "\n";
                }
            }
        } else {
            cout << "No\n";
        }
    }
    return 0;
}