/**
 * 《图解算法》配套代码 - 综合拆解
 * 文件: ch21_comprehensive/04_command_validate.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 04_command_validate 04_command_validate.cpp
 *   ./04_command_validate
 */

int longestValidCmd_dp(string cmd) {
    int n = cmd.size();
    vector<int> dp(n, 0);
    int maxLen = 0;
    for (int i = 1; i < n; i++) {
        if (cmd[i] == ')') {
            if (cmd[i - 1] == '(') {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            } else {
                int matchPos = i - dp[i - 1] - 1;
                if (matchPos >= 0 && cmd[matchPos] == '(') {
                    dp[i] = dp[i - 1] + 2;
                    if (matchPos >= 1) dp[i] += dp[matchPos - 1];
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
    }
    return maxLen;
}