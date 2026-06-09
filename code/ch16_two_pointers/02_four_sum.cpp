/**
 * 《图解算法》配套代码 - 双指针高阶
 * 文件: ch16_two_pointers/02_four_sum.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 02_four_sum 02_four_sum.cpp
 *   ./02_four_sum
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            
            int l = j + 1, r = n - 1;
            long long remain = (long long)target - nums[i] - nums[j];
            
            while (l < r) {
                long long sum = (long long)nums[l] + nums[r];
                if (sum == remain) {
                    res.push_back({nums[i], nums[j], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++; r--;
                } else if (sum < remain) {
                    l++;
                } else {
                    r--;
                }
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> res = fourSum(nums, target);
    cout << "目标和四元组结果：" << endl;
    for (auto& quad : res) {
        cout << "[";
        for (int i = 0; i < 4; i++) {
            cout << quad[i];
            if (i < 3) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}