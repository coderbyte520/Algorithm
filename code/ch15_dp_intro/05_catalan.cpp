/**
 * 《图解算法》配套代码 - DP入门与数学公式
 * 文件: ch15_dp_intro/05_catalan.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 05_catalan 05_catalan.cpp
 *   ./05_catalan
 */

// 方法一：利用组合数公式
long long catalan_comb(int n, long long mod = 1e9 + 7) {
    long long result = C(2 * n, n); // 使用前面预计算的组合数函数
    return result * power(n + 1, mod - 2, mod) % mod; // 乘以 (n+1) 的逆元
}

// 方法二：递推简化公式（最优）
// C_n = C_(n-1) * 2*(2n-1) / (n+1)
long long catalan_opt(int n, long long mod = 1e9 + 7) {
    long long result = 1; // C_0 = 1
    for (int i = 1; i <= n; i++) {
        result = result * 2 * (2 * i - 1) % mod;
        result = result * power(i + 1, mod - 2, mod) % mod;
    }
    return result;
}