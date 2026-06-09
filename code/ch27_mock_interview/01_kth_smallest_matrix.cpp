/**
 * 《图解算法》配套代码 - 面试模拟
 * 文件: ch27_mock_interview/01_kth_smallest_matrix.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 01_kth_smallest_matrix 01_kth_smallest_matrix.cpp
 *   ./01_kth_smallest_matrix
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int left = matrix[0][0], right = matrix[n-1][n-1];
    int ans = right;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // 统计 ≤ mid 的元素个数
        int count = 0;
        for (int i = 0; i < n; i++) {
            // 每行从右往左找第一个 ≤ mid 的位置
            int j = n - 1;
            while (j >= 0 && matrix[i][j] > mid) j--;
            count += (j + 1);
        }
        if (count > k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
    cout << "第8小元素：" << kthSmallest(matrix, 8) << endl;
    return 0;
}