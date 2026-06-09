/**
 * 《图解算法》配套代码 - 排序算法
 * 文件: ch07_sorting/01_quicksort.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 01_quicksort 01_quicksort.cpp
 *   ./01_quicksort
 */

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left];
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] > pivot) j--;
        while (i < j && nums[i] <= pivot) i++;
        if (i < j) swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[j]);
    return j;
}

void quickSort(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    int pi = partition(nums, left, right);
    quickSort(nums, left, pi - 1);
    quickSort(nums, pi + 1, right);
}

int main() {
    vector<int> nums = {5, 2, 9, 1, 5, 6};
    quickSort(nums, 0, nums.size() - 1);
    cout << "快速排序结果：";
    for (int x : nums) cout << x << " ";
    cout << endl;
    return 0;
}