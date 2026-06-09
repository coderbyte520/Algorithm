/**
 * 《图解算法》配套代码 - DP入门与数学公式
 * 文件: ch15_dp_intro/07_derangement.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 07_derangement 07_derangement.cpp
 *   ./07_derangement
 */

// 递推
long long derangement_dp(int n, long long mod = 1e9 + 7) {
    if (n == 0) return 1;
    if (n == 1) return 0;

    long long prev2 = 1; // D(0)
    long long prev1 = 0; // D(1)

    for (int i = 2; i <= n; i++) {
        long long curr = (long long)(i - 1) * (prev1 + prev2) % mod;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}