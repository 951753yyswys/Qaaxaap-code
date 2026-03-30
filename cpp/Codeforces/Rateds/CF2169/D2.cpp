#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long find_kth_number(long long x, long long y, long long k) {
    // 使用二分法来找第k个位置的数
    long long left = 1, right = x;
    
    while (left < right) {
        long long mid = (left + right) / 2;
        
        // 计算1到mid的序列中，已经被删除的元素数量
        long long deleted = mid / y;
        
        // 计算剩余元素数量
        long long remaining = mid - deleted;
        
        if (remaining >= k) {
            // 如果剩余元素数量大于等于k，说明我们可能在这个范围内找到答案
            right = mid;
        } else {
            // 否则继续向右侧查找
            left = mid + 1;
        }
    }
    
    return left;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;

        // 找出第k个位置的数
        long long result = find_kth_number(x, y, k);
        
        // 检查最终序列的长度是否小于k
        long long deleted = result / y;
        long long remaining = result - deleted;
        
        if (remaining >= k) {
            cout << result << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}
