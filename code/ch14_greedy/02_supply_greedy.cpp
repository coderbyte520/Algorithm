/**
 * 《图解算法》配套代码 - 贪心算法
 * 文件: ch14_greedy/02_supply_greedy.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 02_supply_greedy 02_supply_greedy.cpp
 *   ./02_supply_greedy
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int distributeSupplies(vector<int>& needs, vector<int>& supplies) {
    sort(needs.begin(), needs.end());
    sort(supplies.begin(), supplies.end());
    int vol = 0, sup = 0;
    while (vol < needs.size() && sup < supplies.size()) {
        if (supplies[sup] >= needs[vol]) vol++;
        sup++;
    }
    return vol;
}

int main() {
    vector<int> needs = {1, 2, 3};
    vector<int> supplies = {1, 1};
    cout << "最多满足志愿者数：" << distributeSupplies(needs, supplies) << endl;
    return 0;
}