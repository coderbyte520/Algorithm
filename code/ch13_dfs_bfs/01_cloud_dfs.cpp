/**
 * 《图解算法》配套代码 - DFS与BFS
 * 文件: ch13_dfs_bfs/01_cloud_dfs.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 01_cloud_dfs 01_cloud_dfs.cpp
 *   ./01_cloud_dfs
 */

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& grid, int r, int c) {
    int rows = grid.size(), cols = grid[0].size();
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0') return;
    grid[r][c] = '0';
    dfs(grid, r+1, c); dfs(grid, r-1, c);
    dfs(grid, r, c+1); dfs(grid, r, c-1);
}

int countClouds(vector<vector<char>>& grid) {
    int count = 0;
    for (int r = 0; r < grid.size(); r++)
        for (int c = 0; c < grid[0].size(); c++)
            if (grid[r][c] == '1') { count++; dfs(grid, r, c); }
    return count;
}

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'}, {'1','1','0','0','0'},
        {'0','0','1','0','0'}, {'0','0','0','1','1'}
    };
    cout << "云团数量：" << countClouds(grid) << endl;
    return 0;
}