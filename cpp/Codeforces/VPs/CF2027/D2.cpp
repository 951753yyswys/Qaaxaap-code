#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

const long long INF = 1e18;
const int MOD = 1e9 + 7;

struct State {
    long long cost;
    long long count;
    State() : cost(INF), count(0) {}
    State(long long c, long long cnt) : cost(c), count(cnt) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<long long> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        
        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + a[i - 1];
        }
        
        vector<vector<State>> dp(n + 1, vector<State>(m + 1));
        dp[0][1] = State(0, 1);
        
        for (int i = 0; i <= n; i++) {
            for (int k = 1; k <= m; k++) {
                if (dp[i][k].cost == INF) continue;
                
                // Type 1 operation: increase k
                if (k < m) {
                    if (dp[i][k].cost < dp[i][k + 1].cost) {
                        dp[i][k + 1] = dp[i][k];
                    } else if (dp[i][k].cost == dp[i][k + 1].cost) {
                        dp[i][k + 1].count = (dp[i][k + 1].count + dp[i][k].count) % MOD;
                    }
                }
                
                // Type 2 operation: delete prefix
                // Find maximum j such that prefix[j] - prefix[i] <= b[k-1]
                int left = i + 1, right = n, max_j = i;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (prefix[mid] - prefix[i] <= b[k - 1]) {
                        max_j = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                
                if (max_j > i) {
                    State new_state(dp[i][k].cost + (m - k), dp[i][k].count);
                    if (new_state.cost < dp[max_j][k].cost) {
                        dp[max_j][k] = new_state;
                    } else if (new_state.cost == dp[max_j][k].cost) {
                        dp[max_j][k].count = (dp[max_j][k].count + new_state.count) % MOD;
                    }
                }
            }
        }
        
        // Find the best result among all k values for position n
        State result;
        for (int k = 1; k <= m; k++) {
            if (dp[n][k].cost < result.cost) {
                result = dp[n][k];
            } else if (dp[n][k].cost == result.cost) {
                result.count = (result.count + dp[n][k].count) % MOD;
            }
        }
        
        if (result.cost == INF) {
            cout << -1 << '\n';
        } else {
            cout << result.cost << " " << result.count % MOD << '\n';
        }
    }
    
    return 0;
}