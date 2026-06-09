/**
 * 《图解算法》配套代码 - 工程迁移
 * 文件: ch28_engineering/02_coverage_map.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 02_coverage_map 02_coverage_map.cpp
 *   ./02_coverage_map
 */

#include <iostream>
#include <vector>
using namespace std;

// 二维前缀和：快速查询任意矩形区域的覆盖次数
class CoverageMap {
    vector<vector<int>> prefix;
    int rows, cols;
    
public:
    CoverageMap(int r, int c) : rows(r), cols(c) {
        prefix.assign(r + 1, vector<int>(c + 1, 0));
    }
    
    // 添加一张影像的覆盖区域 [r1,c1] 到 [r2,c2]
    void addCoverage(int r1, int c1, int r2, int c2) {
        // 差分数组
        prefix[r1][c1] += 1;
        if (r2 + 1 <= rows) prefix[r2 + 1][c1] -= 1;
        if (c2 + 1 <= cols) prefix[r1][c2 + 1] -= 1;
        if (r2 + 1 <= rows && c2 + 1 <= cols) prefix[r2 + 1][c2 + 1] += 1;
    }
    
    // 计算前缀和
    void build() {
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                prefix[i][j] += prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }
    }
    
    // 查询某点的覆盖次数
    int query(int r, int c) {
        return prefix[r][c];
    }
};

int main() {
    CoverageMap map(10, 10);
    map.addCoverage(1, 1, 5, 5);   // 影像1
    map.addCoverage(3, 3, 8, 8);   // 影像2
    map.addCoverage(2, 2, 6, 6);   // 影像3
    map.build();
    
    cout << "点(4,4)覆盖次数：" << map.query(4, 4) << endl;  // 3张都覆盖
    cout << "点(1,1)覆盖次数：" << map.query(1, 1) << endl;  // 仅影像1
    cout << "点(7,7)覆盖次数：" << map.query(7, 7) << endl;  // 仅影像2
    return 0;
}