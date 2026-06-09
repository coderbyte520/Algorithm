/**
 * 《图解算法》配套代码 - 双指针高阶
 * 文件: ch16_two_pointers/01_three_sum.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 01_three_sum 01_three_sum.cpp
 *   ./01_three_sum
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        int l = i + 1, r = n - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0) {
                res.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l + 1]) l++;
                while (l < r && nums[r] == nums[r - 1]) r--;
                l++;
                r--;
            } else if (sum < 0) {
                l++;
            } else {
                r--;
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = threeSum(nums);
    cout << "零和三元组结果：" << endl;
    for (auto& triple : res) {
        cout << "[";
        for (int i = 0; i < 3; i++) {
            cout << triple[i];
            if (i < 2) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}