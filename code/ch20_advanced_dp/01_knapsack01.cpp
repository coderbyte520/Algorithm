/**
 * 《图解算法》配套代码 - 高阶DP
 * 文件: ch20_advanced_dp/01_code.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 01_code 01_code.cpp
 *   ./01_code
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(vector<int>& weight, vector<int>& value, int W) {
    int n = weight.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= weight[i - 1]) {
                dp[i][j] = max(dp[i][j],
                               dp[i - 1][j - weight[i - 1]] + value[i - 1]);
            }
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> weight = {2, 3, 4, 5};
    vector<int> value = {3, 4, 5, 6};
    int W = 8;
    cout << "0-1背包最大价值：" << knapsack(weight, value, W) << endl;
    return 0;
}