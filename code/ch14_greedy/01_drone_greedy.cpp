/**
 * 《图解算法》配套代码 - 贪心算法
 * 文件: ch14_greedy/01_drone_greedy.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 01_drone_greedy 01_drone_greedy.cpp
 *   ./01_drone_greedy
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canFly(vector<int>& power) {
    int maxReach = 0, n = power.size();
    for (int i = 0; i < n; i++) {
        if (i > maxReach) return false;
        maxReach = max(maxReach, i + power[i]);
        if (maxReach >= n - 1) return true;
    }
    return true;
}

int main() {
    vector<int> p1 = {2, 3, 1, 1, 4};
    vector<int> p2 = {3, 2, 1, 0, 4};
    cout << boolalpha << canFly(p1) << endl;  // true
    cout << boolalpha << canFly(p2) << endl;  // false
    return 0;
}