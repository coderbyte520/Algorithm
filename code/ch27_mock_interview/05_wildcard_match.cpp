/**
 * 《图解算法》配套代码 - 面试模拟
 * 文件: ch27_mock_interview/05_wildcard_match.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 05_wildcard_match 05_wildcard_match.cpp
 *   ./05_wildcard_match
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    
    // p的前j个字符全是'*'时，可以匹配空串
    for (int j = 1; j <= n; j++) {
        if (p[j-1] == '*') dp[0][j] = dp[0][j-1];
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '*') {
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
                // '*'匹配空(dp[i][j-1]) 或 匹配当前字符(dp[i-1][j])
            } else if (p[j-1] == '?' || s[i-1] == p[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    return dp[m][n];
}

int main() {
    cout << boolalpha << isMatch("adceb", "*a*b") << endl;
    return 0;
}