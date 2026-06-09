/**
 * 《图解算法》配套代码 - 面试模拟
 * 文件: ch27_mock_interview/02_permute_unique.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 02_permute_unique 02_permute_unique.cpp
 *   ./02_permute_unique
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void backtrack(string& s, vector<bool>& used, string& path, vector<string>& res) {
    if (path.size() == s.size()) {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        if (used[i]) continue;
        // 同层去重：如果与前一个相同且前一个未被使用，跳过
        if (i > 0 && s[i] == s[i-1] && !used[i-1]) continue;
        
        used[i] = true;
        path.push_back(s[i]);
        backtrack(s, used, path, res);
        path.pop_back();
        used[i] = false;
    }
}

vector<string> permuteUnique(string s) {
    sort(s.begin(), s.end());
    vector<string> res;
    string path;
    vector<bool> used(s.size(), false);
    backtrack(s, used, path, res);
    return res;
}

int main() {
    string s = "aab";
    vector<string> res = permuteUnique(s);
    cout << "全排列结果：";
    for (auto& p : res) cout << p << " ";
    cout << endl;
    return 0;
}