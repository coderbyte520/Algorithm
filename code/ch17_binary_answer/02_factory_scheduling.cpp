/**
 * 《图解算法》配套代码 - 二分答案
 * 文件: ch17_binary_answer/02_factory_scheduling.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 02_factory_scheduling 02_factory_scheduling.cpp
 *   ./02_factory_scheduling
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(const vector<int>& orders, int h, int k) {
    long long hours = 0;
    for (int p : orders) {
        hours += (p + k - 1) / k;  // 等价于 ceil(p / k)，避免浮点运算
    }
    return hours <= h;
}

int minSpeed(vector<int>& orders, int h) {
    int left = 1;
    int right = *max_element(orders.begin(), orders.end());
    int ans = right;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(orders, h, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> orders = {3, 6, 7, 11};
    int h = 8;
    cout << "最小生产速度：" << minSpeed(orders, h) << endl;
    return 0;
}