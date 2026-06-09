/**
 * 《图解算法》配套代码 - 综合拆解
 * 文件: ch21_comprehensive/02_skyline_water.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 02_skyline_water 02_skyline_water.cpp
 *   ./02_skyline_water
 */

int trapWaterOpt(vector<int>& heights) {
    int l = 0, r = heights.size() - 1;
    int lMax = 0, rMax = 0, water = 0;
    while (l < r) {
        lMax = max(lMax, heights[l]);
        rMax = max(rMax, heights[r]);
        if (lMax < rMax) {
            water += lMax - heights[l];
            l++;
        } else {
            water += rMax - heights[r];
            r--;
        }
    }
    return water;
}