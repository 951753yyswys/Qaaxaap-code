#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
vector<int> graph[MAXN];
int dist1[MAXN], dist2[MAXN];

void bfs(int start, int dist[]) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : graph[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    // 第一次BFS：从任意点(1)找到直径的一个端点
    memset(dist1, -1, sizeof(dist1));
    bfs(1, dist1);
    
    int endpoint1 = 1;
    for (int i = 2; i <= n; i++) {
        if (dist1[i] > dist1[endpoint1]) {
            endpoint1 = i;
        }
    }
    
    // 第二次BFS：从第一个端点找到第二个端点，并记录距离
    memset(dist1, -1, sizeof(dist1));
    bfs(endpoint1, dist1);
    
    int endpoint2 = endpoint1;
    for (int i = 1; i <= n; i++) {
        if (dist1[i] > dist1[endpoint2]) {
            endpoint2 = i;
        }
    }
    
    // 第三次BFS：从第二个端点记录距离
    memset(dist2, -1, sizeof(dist2));
    bfs(endpoint2, dist2);
    
    // 对于每个顶点，选择更远的直径端点
    for (int i = 1; i <= n; i++) {
        if (dist1[i] > dist2[i]) {
            cout << endpoint1 << "\n";
        } else if (dist2[i] > dist1[i]) {
            cout << endpoint2 << "\n";
        } else {
            // 距离相等时选择编号较大的端点
            cout << max(endpoint1, endpoint2) << "\n";
        }
    }
    
    return 0;
}