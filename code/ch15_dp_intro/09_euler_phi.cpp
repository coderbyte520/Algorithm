/**
 * 《图解算法》配套代码 - DP入门与数学公式
 * 文件: ch15_dp_intro/09_euler_phi.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 09_euler_phi 09_euler_phi.cpp
 *   ./09_euler_phi
 */

// 单个数的欧拉函数
long long euler_phi(long long n) {
    long long result = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            result = result / i * (i - 1); // 先除后乘，避免溢出
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) result = result / n * (n - 1);
    return result;
}