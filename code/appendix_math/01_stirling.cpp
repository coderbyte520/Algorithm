/**
 * 《图解算法》配套代码 - 竞赛数学
 * 文件: appendix_math/01_stirling.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 01_stirling 01_stirling.cpp
 *   ./01_stirling
 */

vector<vector<long long>> stirling2(int n, int k, long long mod = 1e9 + 7) {
    vector<vector<long long>> S(n + 1, vector<long long>(k + 1, 0));
    S[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            S[i][j] = (j * S[i - 1][j] % mod + S[i - 1][j - 1]) % mod;
        }
    }
    return S;
}