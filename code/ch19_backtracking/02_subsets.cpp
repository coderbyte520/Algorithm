/**
 * 《图解算法》配套代码 - 回溯算法
 * 文件: ch19_backtracking/02_subsets.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 02_subsets 02_subsets.cpp
 *   ./02_subsets
 */

#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& cands, int start,
               vector<int>& path, vector<vector<int>>& res) {
    res.push_back(path);
    for (int i = start; i < cands.size(); i++) {
        path.push_back(cands[i]);
        backtrack(cands, i + 1, path, res);
        path.pop_back();
    }
}

vector<vector<int>> allTeams(vector<int>& candidates) {
    vector<vector<int>> res;
    vector<int> path;
    backtrack(candidates, 0, path, res);
    return res;
}

int main() {
    vector<int> candidates = {1, 2, 3};
    vector<vector<int>> res = allTeams(candidates);
    cout << "组队方案：" << endl;
    for (auto& team : res) {
        cout << "[";
        for (int i = 0; i < team.size(); i++) {
            cout << team[i];
            if (i < team.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}