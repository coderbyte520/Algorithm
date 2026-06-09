/**
 * 《图解算法》配套代码 - 字符串
 * 文件: ch06_strings/01_palindrome.cpp
 * 难度: 🟢简单
 *
 * 编译运行:
 *   g++ -std=c++17 -o palindrome 01_palindrome.cpp
 *   ./palindrome
 */

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

int main() {
    cout << boolalpha;
    cout << isPalindrome("racecar") << endl; // true
    cout << isPalindrome("hello") << endl; // false
    return 0;
}
