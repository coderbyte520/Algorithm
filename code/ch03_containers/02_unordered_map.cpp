/**
 * 《图解算法》配套代码 - 容器
 * 文件: ch03_containers/02_unordered_map.cpp
 * 难度: 🟢简单
 *
 * 编译运行:
 *   g++ -std=c++17 -o unordered_map 02_unordered_map.cpp
 *   ./unordered_map
 */

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> scores;
    scores["Alice"] = 95;
    scores["Bob"] = 87;
    scores["Charlie"] = 92;
    
    for (auto& [name, score] : scores) {
        cout << name << ": " << score << endl;
    }
    
    // 查找
    if (scores.count("Bob")) {
        cout << "Bob's score: " << scores["Bob"] << endl;
    }
    
    return 0;
}
