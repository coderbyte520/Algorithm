/**
 * 《图解算法》配套代码 - 二分答案
 * 文件: ch17_binary_answer/01_wood_cutting.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 01_wood_cutting 01_wood_cutting.cpp
 *   ./01_wood_cutting
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(const vector<int>& L, int k, int len) {
    int count = 0;
    for (int x : L) {
        count += x / len;
    }
    return count >= k;
}

int main() {
    vector<int> L = {4, 7, 9, 5};
    int k = 5;
    
    int left = 1;
    int right = *max_element(L.begin(), L.end());
    int ans = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(L, k, mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << "每段最大长度：" << ans << endl;
    return 0;
}