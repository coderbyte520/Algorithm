/**
 * 《图解算法》配套代码 - DP入门与数学公式
 * 文件: ch15_dp_intro/02_frog_jump_dp.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 02_frog_jump_dp 02_frog_jump_dp.cpp
 *   ./02_frog_jump_dp
 */

int jump_dp(int n) {
    if (n <= 2) return n;
    vector<int> dp(n+1);
    dp[1] = 1; dp[2] = 2;
    for (int i = 3; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}