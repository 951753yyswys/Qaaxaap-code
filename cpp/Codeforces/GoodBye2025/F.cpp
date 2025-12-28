#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 998244353

using namespace std;

vector<int> tree[200005];
int size[200005];
bool color[200005];  // true for white, false for black

// DFS to calculate subtree sizes and determine node colors
void dfs(int node, int parent) {
    size[node] = 1;
    color[node] = false;  // start with black
    for (int child : tree[node]) {
        if (child != parent) {
            dfs(child, node);
            size[node] += size[child];
        }
    }
    if (size[node] % 2 == 0) {
        color[node] = true;  // white if subtree size is even
    }
}

// Function to compute the number of different conquerable trees
int computeConquerableTrees(int n) {
    int whiteCount = 0;
    for (int i = 1; i <= n; ++i) {
        if (color[i]) {
            ++whiteCount;
        }
    }
    return (1 << whiteCount) % MOD;  // 2^whiteCount % MOD
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        // Clear the tree structure and reset other arrays
        for (int i = 1; i <= n; ++i) {
            tree[i].clear();
        }
        
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        
        // Perform DFS from the root (node 1)
        dfs(1, -1);
        
        // Calculate the number of conquerable trees
        int result = computeConquerableTrees(n);
        
        cout << result << endl;
    }
    
    return 0;
}
