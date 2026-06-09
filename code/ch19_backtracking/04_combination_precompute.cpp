/**
 * 《图解算法》配套代码 - 回溯算法
 * 文件: ch19_backtracking/04_fast_power.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 04_fast_power 04_fast_power.cpp
 *   ./04_fast_power
 */

const int MAXN = 1e6 + 5;
const long long MOD = 1e9 + 7;
long long fact[MAXN], inv_fact[MAXN];

// 快速幂
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

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = fact[i - 1] * i % MOD;

    inv_fact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2, MOD); // 逆元
    for (int i = MAXN - 2; i >= 0; i--)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

long long C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}