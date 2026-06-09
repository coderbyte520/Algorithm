/**
 * 《图解算法》配套代码 - DP入门与数学公式
 * 文件: ch15_dp_intro/03_frog_jump_dp.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 03_frog_jump_dp 03_frog_jump_dp.cpp
 *   ./03_frog_jump_dp
 */

#include <iostream>
#include <vector>
using namespace std;

int jump(int n) {
    if (n <= 2) return n;
    int prev2 = 1, prev1 = 2;
    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    cout << "青蛙跳荷叶方案数(n=4)：" << jump(4) << endl;
    return 0;
}