/**
 * 《图解算法》配套代码 - 算法入门
 * 文件: ch01_algorithm_basics/01_two_sum_brute.cpp
 * 难度: 🟢简单
 *
 * 编译运行:
 *   g++ -std=c++17 -o two_sum_brute 01_two_sum_brute.cpp
 *   ./two_sum_brute
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = twoSum(nums, target);
    cout << "[" << res[0] << ", " << res[1] << "]" << endl;
    return 0;
}
