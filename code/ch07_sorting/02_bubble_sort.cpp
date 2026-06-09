/**
 * 《图解算法》配套代码 - 排序
 * 文件: ch07_sorting/02_bubble_sort.cpp
 * 难度: 🟢简单
 *
 * 编译运行:
 *   g++ -std=c++17 -o bubble_sort 02_bubble_sort.cpp
 *   ./bubble_sort
 */

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // 优化：已有序则提前退出
    }
}

int main() {
    vector<int> nums = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(nums);
    for (int x : nums) cout << x << " ";
    cout << endl;
    return 0;
}
