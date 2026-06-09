/**
 * 《图解算法》配套代码 - 回溯算法
 * 文件: ch19_backtracking/03_combination_sum.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 03_combination_sum 03_combination_sum.cpp
 *   ./03_combination_sum
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(vector<int>& cards, int target, int start,
               int sum, vector<int>& path, vector<vector<int>>& res) {
    if (sum == target) {
        res.push_back(path);
        return;
    }
    for (int i = start; i < cards.size(); i++) {
        if (sum + cards[i] > target) break;
        path.push_back(cards[i]);
        backtrack(cards, target, i, sum + cards[i], path, res);
        path.pop_back();
    }
}

vector<vector<int>> redeemPlans(vector<int>& cards, int target) {
    sort(cards.begin(), cards.end());
    vector<vector<int>> res;
    vector<int> path;
    backtrack(cards, target, 0, 0, path, res);
    return res;
}

int main() {
    vector<int> cards = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> res = redeemPlans(cards, target);
    cout << "积分兑换方案：" << endl;
    for (auto& plan : res) {
        cout << "[";
        for (int i = 0; i < plan.size(); i++) {
            cout << plan[i];
            if (i < plan.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}