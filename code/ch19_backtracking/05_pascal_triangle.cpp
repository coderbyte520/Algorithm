/**
 * 《图解算法》配套代码 - 回溯算法
 * 文件: ch19_backtracking/05_pascal_triangle.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 05_pascal_triangle 05_pascal_triangle.cpp
 *   ./05_pascal_triangle
 */

vector<vector<long long>> pascal(int n) {
    vector<vector<long long>> dp(n + 1);
    for (int i = 0; i <= n; i++) {
        dp[i].resize(i + 1, 0);
        dp[i][0] = dp[i][i] = 1;
        for (int j = 1; j < i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp;
}