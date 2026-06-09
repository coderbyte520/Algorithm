/**
 * 《图解算法》配套代码 - 跨技巧综合
 * 文件: ch26_cross_technique/02_task_scheduling.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 02_task_scheduling 02_task_scheduling.cpp
 *   ./02_task_scheduling
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(const vector<int>& time, int k, int maxCost) {
    int groups = 1, currentSum = 0;
    for (int t : time) {
        if (t > maxCost) return false;  // 单个任务超限
        if (currentSum + t > maxCost) {
            groups++;
            currentSum = t;
        } else {
            currentSum += t;
        }
    }
    return groups <= k;
}

int minMaxGroupCost(vector<int>& time, int k) {
    int left = *max_element(time.begin(), time.end());
    int right = 0;
    for (int t : time) right += t;
    int ans = right;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(time, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> time = {3, 2, 4, 1, 5, 2};
    int k = 3;
    cout << "最小最大组耗时：" << minMaxGroupCost(time, k) << endl;
    return 0;
}