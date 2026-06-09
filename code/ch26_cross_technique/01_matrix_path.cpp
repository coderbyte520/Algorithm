/**
 * 《图解算法》配套代码 - 跨技巧综合
 * 文件: ch26_cross_technique/01_matrix_path.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 01_matrix_path 01_matrix_path.cpp
 *   ./01_matrix_path
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dp[i][j] = {最少格子数, 该路径最小成本}
// 格子数优先，格子数相同时取成本小的
int minPathGrids(vector<vector<int>>& cost, int budget) {
    int m = cost.size(), n = cost[0].size();
    // {格子数, 成本}，格子数=INT_MAX表示无效
    vector<vector<pair<int,int>>> dp(m, vector<pair<int,int>>(n, {INT_MAX, INT_MAX}));
    
    dp[0][0] = {1, cost[0][0]};
    
    // 第一行
    for (int j = 1; j < n; j++) {
        if (dp[0][j-1].first != INT_MAX) {
            dp[0][j] = {dp[0][j-1].first + 1, dp[0][j-1].second + cost[0][j]};
        }
    }
    // 第一列
    for (int i = 1; i < m; i++) {
        if (dp[i-1][0].first != INT_MAX) {
            dp[i][0] = {dp[i-1][0].first + 1, dp[i-1][0].second + cost[i][0]};
        }
    }
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            auto fromTop = dp[i-1][j];
            auto fromLeft = dp[i][j-1];
            
            // 选择格子数最少的来源
            pair<int,int> best = {INT_MAX, INT_MAX};
            if (fromTop.first < fromLeft.first) {
                best = {fromTop.first + 1, fromTop.second + cost[i][j]};
            } else if (fromLeft.first < fromTop.first) {
                best = {fromLeft.first + 1, fromLeft.second + cost[i][j]};
            } else {
                // 格子数相同，取成本小的
                int minCost = min(fromTop.second, fromLeft.second);
                best = {fromTop.first + 1, minCost + cost[i][j]};
            }
            dp[i][j] = best;
        }
    }
    
    auto result = dp[m-1][n-1];
    if (result.first == INT_MAX || result.second > budget) return -1;
    return result.first;
}

int main() {
    vector<vector<int>> cost = {{1,3,1},{1,5,1},{4,2,1}};
    int budget = 7;
    cout << "最少经过格子数：" << minPathGrids(cost, budget) << endl;
    return 0;
}