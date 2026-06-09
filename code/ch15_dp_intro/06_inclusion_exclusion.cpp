/**
 * 《图解算法》配套代码 - DP入门与数学公式
 * 文件: ch15_dp_intro/06_inclusion_exclusion.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 06_inclusion_exclusion 06_inclusion_exclusion.cpp
 *   ./06_inclusion_exclusion
 */

// 经典应用：1~n 中能被集合 {p1, p2, ..., pk} 中至少一个整除的数的个数
long long inclusion_exclusion(long long n, vector<long long>& primes) {
    int k = primes.size();
    long long result = 0;

    // 枚举所有非空子集（状态压缩）
    for (int mask = 1; mask < (1 << k); mask++) {
        long long product = 1;
        int bits = 0;
        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                product *= primes[i];
                bits++;
                if (product > n) break;
            }
        }
        if (product > n) continue;

        long long count = n / product;
        if (bits % 2 == 1) {
            result += count; // 奇数个集合，加
        } else {
            result -= count; // 偶数个集合，减
        }
    }
    return result;
}