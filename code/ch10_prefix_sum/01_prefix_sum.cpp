/**
 * 《图解算法》配套代码 - 前缀和
 * 文件: ch10_prefix_sum/01_prefix_sum.cpp
 * 难度: 🟡中等
 *
 * 编译运行:
 *   g++ -std=c++17 -o prefix_sum 01_prefix_sum.cpp
 *   ./prefix_sum
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = nums.size();
    
    // 构建前缀和数组
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    
    // 查询区间和 [l, r]
    int l = 1, r = 3; // 下标1到3
    int sum = prefix[r + 1] - prefix[l];
    cout << "Sum [" << l << ", " << r << "]: " << sum << endl;
    
    return 0;
}
