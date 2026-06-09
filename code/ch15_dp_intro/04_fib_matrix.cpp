/**
 * 《图解算法》配套代码 - DP入门与数学公式
 * 文件: ch15_dp_intro/04_fib_matrix.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 04_fib_matrix 04_fib_matrix.cpp
 *   ./04_fib_matrix
 */

typedef vector<vector<long long>> Matrix;

// 矩阵乘法
Matrix multiply(const Matrix& A, const Matrix& B, long long mod = 1e9 + 7) {
    int n = A.size();
    Matrix C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            for (int j = 0; j < n; j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}

// 矩阵快速幂
Matrix matrix_pow(Matrix base, long long exp, long long mod = 1e9 + 7) {
    int n = base.size();
    Matrix result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) result[i][i] = 1; // 单位矩阵
    
    while (exp > 0) {
        if (exp & 1) result = multiply(result, base, mod);
        base = multiply(base, base, mod);
        exp >>= 1;
    }
    return result;
}

// 斐波那契 O(log n)
long long fib_matrix(long long n, long long mod = 1e9 + 7) {
    if (n <= 1) return n;
    Matrix T = {{1, 1}, {1, 0}};
    Matrix result = matrix_pow(T, n - 1, mod);
    return result[0][0]; // F(n)
}