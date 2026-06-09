/**
 * 《图解算法》配套代码 - 哈希
 * 文件: ch05_hashing/01_valid_anagram.cpp
 * 难度: 🟢简单
 *
 * 编译运行:
 *   g++ -std=c++17 -o valid_anagram 01_valid_anagram.cpp
 *   ./valid_anagram
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    
    unordered_map<char, int> count;
    for (char c : s) count[c]++;
    for (char c : t) {
        count[c]--;
        if (count[c] < 0) return false;
    }
    return true;
}

int main() {
    cout << boolalpha;
    cout << isAnagram("anagram", "nagaram") << endl; // true
    cout << isAnagram("rat", "car") << endl; // false
    return 0;
}
