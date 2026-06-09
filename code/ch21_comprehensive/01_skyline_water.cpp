/**
 * 《图解算法》配套代码 - 综合拆解
 * 文件: ch21_comprehensive/01_skyline_water.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 01_skyline_water 01_skyline_water.cpp
 *   ./01_skyline_water
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trapWater(vector<int>& heights) {
    int n = heights.size();
    if (n == 0) return 0;
    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = heights[0];
    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i - 1], heights[i]);
    rightMax[n - 1] = heights[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rightMax[i] = max(rightMax[i + 1], heights[i]);
    int water = 0;
    for (int i = 0; i < n; i++)
        water += min(leftMax[i], rightMax[i]) - heights[i];
    return water;
}