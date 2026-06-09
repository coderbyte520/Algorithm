/**
 * 《图解算法》配套代码 - 竞赛数学
 * 文件: appendix_math/04_code.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 04_code 04_code.cpp
 *   ./04_code
 */

long long C_small(long long n, long long m, long long p) {
    if (m < 0 || m > n) return 0;
    if (m > n - m) m = n - m;
    long long num = 1, den = 1;
    for (long long i = 0; i < m; i++) {
        num = num * (n - i) % p;
        den = den * (i + 1) % p;
    }
    return num * power(den, p - 2, p) % p;
}

long long lucas(long long n, long long m, long long p) {
    if (m == 0) return 1;
    if (n < m) return 0;
    return C_small(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}