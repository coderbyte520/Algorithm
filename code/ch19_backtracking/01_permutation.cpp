/**
 * 《图解算法》配套代码 - 回溯算法
 * 文件: ch19_backtracking/01_permutation.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 01_permutation 01_permutation.cpp
 *   ./01_permutation
 */

#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& guests, vector<int>& path,
               vector<bool>& used, vector<vector<int>>& res) {
    if (path.size() == guests.size()) {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < guests.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        path.push_back(guests[i]);
        backtrack(guests, path, used, res);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> allArrangements(vector<int>& guests) {
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used(guests.size(), false);
    backtrack(guests, path, used, res);
    return res;
}

int main() {
    vector<int> guests = {1, 2, 3};
    vector<vector<int>> res = allArrangements(guests);
    cout << "座位排列方案：" << endl;
    for (auto& arr : res) {
        cout << "[";
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i];
            if (i < arr.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}