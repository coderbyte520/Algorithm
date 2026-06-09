/**
 * 《图解算法》配套代码 - 容器
 * 文件: ch03_containers/01_vector_sum.cpp
 * 难度: 🟢简单
 *
 * 编译运行:
 *   g++ -std=c++17 -o vector_sum 01_vector_sum.cpp
 *   ./vector_sum
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int sum = 0;
    for (int x : nums) {
        sum += x;
    }
    cout << "Sum: " << sum << endl;
    return 0;
}
