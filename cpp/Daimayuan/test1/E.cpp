#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int M = 31; // 2^30

// 数位DP用于countA
ll dpA[32][2][2];
int A_bits[32], B_bits[32];

ll dfsA(int pos, bool tight_x, bool tight_y) {
    if (pos == M) return 1;
    if (dpA[pos][tight_x][tight_y] != -1) return dpA[pos][tight_x][tight_y];
    
    int upper_x = tight_x ? A_bits[pos] : 1;
    int upper_y = tight_y ? B_bits[pos] : 1;
    ll res = 0;
    
    for (int x_bit = 0; x_bit <= upper_x; x_bit++) {
        for (int y_bit = 0; y_bit <= upper_y; y_bit++) {
            if (x_bit & y_bit) continue; // x & y != 0, skip
            res += dfsA(pos + 1, 
                       tight_x && (x_bit == upper_x),
                       tight_y && (y_bit == upper_y));
        }
    }
    return dpA[pos][tight_x][tight_y] = res;
}

ll countA(ll a, ll b) {
    if (a < 0 || b < 0) return 0;
    memset(dpA, -1, sizeof(dpA));
    for (int i = 0; i < M; i++) {
        A_bits[M-1-i] = (a >> i) & 1;
        B_bits[M-1-i] = (b >> i) & 1;
    }
    return dfsA(0, true, true);
}

// 数位DP用于countB (水平相邻)
ll dpB[32][2][2][2]; // 最后一位是进位

ll dfsB(int pos, bool tight_x, bool tight_y, int carry) {
    if (pos == M) return 1;
    if (dpB[pos][tight_x][tight_y][carry] != -1) 
        return dpB[pos][tight_x][tight_y][carry];
    
    int upper_x = tight_x ? A_bits[pos] : 1;
    int upper_y = tight_y ? B_bits[pos] : 1;
    ll res = 0;
    
    for (int x_bit = 0; x_bit <= upper_x; x_bit++) {
        for (int y_bit = 0; y_bit <= upper_y; y_bit++) {
            // 计算x+1的当前位
            int cur_bit = (x_bit + carry) % 2;
            int new_carry = (x_bit + carry) / 2;
            
            // 检查条件: x & y == 0 且 (x+1) & y == 0
            if ((x_bit & y_bit) || (cur_bit & y_bit)) continue;
            
            res += dfsB(pos + 1,
                       tight_x && (x_bit == upper_x),
                       tight_y && (y_bit == upper_y),
                       new_carry);
        }
    }
    return dpB[pos][tight_x][tight_y][carry] = res;
}

ll countB(ll a, ll b) {
    if (a < 0 || b < 0) return 0;
    memset(dpB, -1, sizeof(dpB));
    for (int i = 0; i < M; i++) {
        A_bits[M-1-i] = (a >> i) & 1;
        B_bits[M-1-i] = (b >> i) & 1;
    }
    return dfsB(0, true, true, 0);
}

// 数位DP用于countC (垂直相邻)
ll dpC[32][2][2][2]; // 最后一位是进位

ll dfsC(int pos, bool tight_x, bool tight_y, int carry) {
    if (pos == M) return 1;
    if (dpC[pos][tight_x][tight_y][carry] != -1) 
        return dpC[pos][tight_x][tight_y][carry];
    
    int upper_x = tight_x ? A_bits[pos] : 1;
    int upper_y = tight_y ? B_bits[pos] : 1;
    ll res = 0;
    
    for (int x_bit = 0; x_bit <= upper_x; x_bit++) {
        for (int y_bit = 0; y_bit <= upper_y; y_bit++) {
            // 计算y+1的当前位
            int cur_bit = (y_bit + carry) % 2;
            int new_carry = (y_bit + carry) / 2;
            
            // 检查条件: x & y == 0 且 x & (y+1) == 0
            if ((x_bit & y_bit) || (x_bit & cur_bit)) continue;
            
            res += dfsC(pos + 1,
                       tight_x && (x_bit == upper_x),
                       tight_y && (y_bit == upper_y),
                       new_carry);
        }
    }
    return dpC[pos][tight_x][tight_y][carry] = res;
}

ll countC(ll a, ll b) {
    if (a < 0 || b < 0) return 0;
    memset(dpC, -1, sizeof(dpC));
    for (int i = 0; i < M; i++) {
        A_bits[M-1-i] = (a >> i) & 1;
        B_bits[M-1-i] = (b >> i) & 1;
    }
    return dfsC(0, true, true, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    while (n--) {
        ll lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        
        // 使用容斥原理计算矩形区域
        ll A = countA(rx, ry) 
              - (lx > 0 ? countA(lx-1, ry) : 0)
              - (ly > 0 ? countA(rx, ly-1) : 0)
              + (lx > 0 && ly > 0 ? countA(lx-1, ly-1) : 0);
        
        ll B = 0;
        if (rx > 0) {
            B = countB(rx-1, ry)
                - (lx > 0 ? countB(lx-1, ry) : 0)
                - (ly > 0 ? countB(rx-1, ly-1) : 0)
                + (lx > 0 && ly > 0 ? countB(lx-1, ly-1) : 0);
        }
        
        ll C = 0;
        if (ry > 0) {
            C = countC(rx, ry-1)
                - (lx > 0 ? countC(lx-1, ry-1) : 0)
                - (ly > 0 ? countC(rx, ly-1) : 0)
                + (lx > 0 && ly > 0 ? countC(lx-1, ly-1) : 0);
        }
        
        ll result = A - B - C;
        cout << result << "\n";
    }
    
    return 0;
}