/**
 * 《图解算法》配套代码 - 二分查找
 * 文件: ch08_binary_search/01_binary_search.cpp
 * 难度: 🟢简单
 *
 * 编译运行:
 *   g++ -std=c++17 -o binary_search 01_binary_search.cpp
 *   ./binary_search
 */

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11, 13, 15};
    int target = 7;
    int idx = binarySearch(nums, target);
    cout << "Index of " << target << ": " << idx << endl;
    return 0;
}
