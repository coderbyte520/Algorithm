/**
 * 《图解算法》配套代码 - 滑动窗口
 * 文件: ch18_sliding_window/03_gene_locate.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 03_gene_locate 03_gene_locate.cpp
 *   ./03_gene_locate
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string locateGeneSegment(string genome, string targets) {
    unordered_map<char, int> target;
    for (char c : targets) target[c]++;
    
    int need = target.size();
    int l = 0, minLen = INT_MAX, start = 0;
    unordered_map<char, int> window;
    
    for (int r = 0; r < genome.size(); r++) {
        char c = genome[r];
        window[c]++;
        if (target.count(c) && window[c] == target[c])
            need--;
        
        while (need == 0) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                start = l;
            }
            char leftChar = genome[l];
            window[leftChar]--;
            if (target.count(leftChar) && window[leftChar] < target[leftChar])
                need++;
            l++;
        }
    }
    return minLen == INT_MAX ? "" : genome.substr(start, minLen);
}

int main() {
    string genome = "ADOBECODEBANC";
    string targets = "ABC";
    cout << "最短基因标记子片段：" << locateGeneSegment(genome, targets) << endl;
    return 0;
}