/**
 * 《图解算法》配套代码 - 二分答案
 * 文件: ch17_binary_answer/03_fast_power.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 03_fast_power 03_fast_power.cpp
 *   ./03_fast_power
 */

// 快速幂取模
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

// 求逆元（mod 为素数时）
long long mod_inv(long long a, long long mod) {
    return power(a, mod - 2, mod);
}

// 快速乘（防止 a*b 溢出，当 mod > 10^9 时使用）
long long mul_mod(long long a, long long b, long long mod) {
    long long result = 0;
    a %= mod;
    while (b > 0) {
        if (b & 1) result = (result + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return result;
}