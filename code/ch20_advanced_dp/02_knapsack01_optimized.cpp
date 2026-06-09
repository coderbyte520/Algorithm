/**
 * 《图解算法》配套代码 - 高阶DP
 * 文件: ch20_advanced_dp/02_knapsack01_optimized.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 02_knapsack01_optimized 02_knapsack01_optimized.cpp
 *   ./02_knapsack01_optimized
 */

int knapsackOpt(vector<int>& weight, vector<int>& value, int W) {
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < weight.size(); i++) {
        for (int j = W; j >= weight[i]; j--) {  // ⚠️ 必须倒序！
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[W];
}