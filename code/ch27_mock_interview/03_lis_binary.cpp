/**
 * 《图解算法》配套代码 - 面试模拟
 * 文件: ch27_mock_interview/03_lis_binary.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 03_lis_binary 03_lis_binary.cpp
 *   ./03_lis_binary
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;
    for (int num : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) {
            tails.push_back(num);
        } else {
            *it = num;
        }
    }
    return tails.size();
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "最长递增子序列长度：" << lengthOfLIS(nums) << endl;
    return 0;
}