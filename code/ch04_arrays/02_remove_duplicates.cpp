/**
 * 《图解算法》配套代码 - 数组
 * 文件: ch04_arrays/02_remove_duplicates.cpp
 * 难度: 🟡中等
 *
 * 编译运行:
 *   g++ -std=c++17 -o remove_duplicates 02_remove_duplicates.cpp
 *   ./remove_duplicates
 */

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int slow = 0;
    for (int fast = 1; fast < nums.size(); fast++) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }
    return slow + 1;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    int len = removeDuplicates(nums);
    cout << "Length: " << len << endl;
    cout << "Array: ";
    for (int i = 0; i < len; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
