/**
 * 《图解算法》配套代码 - 滑动窗口
 * 文件: ch18_sliding_window/01_signal_dedup.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 01_signal_dedup 01_signal_dedup.cpp
 *   ./01_signal_dedup
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int longestUniqueSubstr(string s) {
    unordered_map<char, int> lastPos;
    int maxLen = 0, l = 0;
    
    for (int r = 0; r < s.size(); r++) {
        if (lastPos.count(s[r]) && lastPos[s[r]] >= l) {
            l = lastPos[s[r]] + 1;
        }
        lastPos[s[r]] = r;
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}

int main() {
    string signal = "abcabcbb";
    cout << "最长无重复子段长度：" << longestUniqueSubstr(signal) << endl;
    return 0;
}