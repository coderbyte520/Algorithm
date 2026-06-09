/**
 * 《图解算法》配套代码 - 数组
 * 文件: ch04_arrays/01_array_max_min.cpp
 * 难度: 🟢简单
 *
 * 编译运行:
 *   g++ -std=c++17 -o array_max_min 01_array_max_min.cpp
 *   ./array_max_min
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6};
    
    int max_val = nums[0];
    int min_val = nums[0];
    
    for (int x : nums) {
        if (x > max_val) max_val = x;
        if (x < min_val) min_val = x;
    }
    
    cout << "Max: " << max_val << endl;
    cout << "Min: " << min_val << endl;
    
    // 或用标准库
    cout << "Max (STL): " << *max_element(nums.begin(), nums.end()) << endl;
    cout << "Min (STL): " << *min_element(nums.begin(), nums.end()) << endl;
    
    return 0;
}
