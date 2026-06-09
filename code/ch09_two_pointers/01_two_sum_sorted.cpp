/**
 * 《图解算法》配套代码 - 双指针
 * 文件: ch09_two_pointers/01_two_sum_sorted.cpp
 * 难度: 🟡中等
 *
 * 编译运行:
 *   g++ -std=c++17 -o two_sum_sorted 01_two_sum_sorted.cpp
 *   ./two_sum_sorted
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum == target) return {l, r};
        else if (sum < target) l++;
        else r--;
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
