/**
 * 《图解算法》配套代码 - 复杂度分析
 * 文件: ch02_complexity/01_arithmetic_geometric.cpp
 * 难度: 简单
 *
 * 编译运行:
 *   g++ -std=c++17 -o 01_arithmetic_geometric 01_arithmetic_geometric.cpp
 *   ./01_arithmetic_geometric
 */

#include <iostream>
#include <cmath>
using namespace std;

// 等差数列求和（注意溢出！用 long long）
long long arithmetic_sum(long long n, long long a1, long long d) {
    return n * a1 + n * (n - 1) / 2 * d;
}

// 快速求 1+2+...+n
long long sum_1_to_n(long long n) {
    return n * (n + 1) / 2;
}

// 等比数列求和（浮点版本）
double geometric_sum(double a1, double r, int n) {
    if (r == 1.0) return a1 * n;
    return a1 * (1 - pow(r, n)) / (1 - r);
}

int main() {
    // 等差数列: 1+2+...+100
    cout << "等差求和 1+2+...+100 = " << sum_1_to_n(100) << endl;

    // 等差数列: 首项3, 公差2, 前10项和
    cout << "等差求和 a1=3,d=2,n=10 = " << arithmetic_sum(10, 3, 2) << endl;

    // 等比数列: 首项2, 公比3, 前4项和
    cout << "等比求和 a1=2,r=3,n=4 = " << geometric_sum(2, 3, 4) << endl;

    return 0;
}
