/**
 * 《图解算法》配套代码 - 容器
 * 文件: ch03_containers/03_string_reverse.cpp
 * 难度: 🟢简单
 *
 * 编译运行:
 *   g++ -std=c++17 -o string_reverse 03_string_reverse.cpp
 *   ./string_reverse
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s = "hello";
    reverse(s.begin(), s.end());
    cout << s << endl; // "olleh"
    return 0;
}
