/**
 * 《图解算法》配套代码 - 竞赛数学
 * 文件: appendix_math/02_mobius.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 02_mobius 02_mobius.cpp
 *   ./02_mobius
 */

const int MAXN = 1e6 + 5;
int mu[MAXN];
bool is_prime[MAXN];
vector<int> primes;

void sieve_mu(int n) {
    fill(is_prime, is_prime + n + 1, true);
    mu[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            mu[i] = -1;
        }
        for (int p : primes) {
            if (i * p > n) break;
            is_prime[i * p] = false;
            if (i % p == 0) {
                mu[i * p] = 0; // p² | i·p
                break;
            } else {
                mu[i * p] = -mu[i]; // 多一个质因子，符号翻转
            }
        }
    }
}