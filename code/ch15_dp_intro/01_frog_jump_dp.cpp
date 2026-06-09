/**
 * 《图解算法》配套代码 - DP入门与数学公式
 * 文件: ch15_dp_intro/01_frog_jump_dp.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 01_frog_jump_dp 01_frog_jump_dp.cpp
 *   ./01_frog_jump_dp
 */

int jump_recursive(int n) {
    if (n <= 2) return n;
    return jump_recursive(n-1) + jump_recursive(n-2);
}