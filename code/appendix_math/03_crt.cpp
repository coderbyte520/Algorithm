/**
 * 《图解算法》配套代码 - 竞赛数学
 * 文件: appendix_math/03_code.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 03_code 03_code.cpp
 *   ./03_code
 */

long long extgcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

long long crt(vector<long long>& a, vector<long long>& m) {
    int k = a.size();
    long long M = 1;
    for (int i = 0; i < k; i++) M *= m[i];

    long long result = 0;
    for (int i = 0; i < k; i++) {
        long long Mi = M / m[i];
        long long x, y;
        extgcd(Mi, m[i], x, y);
        long long ti = (x % m[i] + m[i]) % m[i];
        result = (result + a[i] * Mi % M * ti % M) % M;
    }
    return (result + M) % M;
}