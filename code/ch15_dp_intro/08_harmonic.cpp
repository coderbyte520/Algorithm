/**
 * 《图解算法》配套代码 - DP入门与数学公式
 * 文件: ch15_dp_intro/08_harmonic.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 08_harmonic 08_harmonic.cpp
 *   ./08_harmonic
 */

// 调和级数求和
double harmonic(int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / i;
    }
    return sum;
}