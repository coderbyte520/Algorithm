/**
 * 《图解算法》配套代码 - 工程迁移
 * 文件: ch28_engineering/01_pointcloud_bfs.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 01_pointcloud_bfs 01_pointcloud_bfs.cpp
 *   ./01_pointcloud_bfs
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Point3D {
    double x, y, z;
    int id;
};

// 简化版：用距离阈值代替KD树，判断两点是否"相邻"
double dist(const Point3D& a, const Point3D& b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
}

int detectConnectedComponents(vector<Point3D>& points, double threshold, int minSize) {
    int n = points.size();
    vector<bool> visited(n, false);
    int components = 0;
    
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        
        // BFS
        queue<int> q;
        q.push(i);
        visited[i] = true;
        int size = 0;
        
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            size++;
            
            // 查找所有邻近的未访问点
            for (int j = 0; j < n; j++) {
                if (!visited[j] && dist(points[curr], points[j]) <= threshold) {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
        
        // 过滤小于最小尺寸的噪声碎片
        if (size >= minSize) {
            components++;
        }
    }
    return components;
}

int main() {
    vector<Point3D> points = {
        {0, 0, 0, 0}, {0.5, 0, 0, 1}, {1, 0, 0, 2},  // 连通分量1
        {10, 10, 10, 3}, {10.5, 10, 10, 4},           // 连通分量2
        {50, 50, 50, 5}                                 // 噪声点（太小）
    };
    
    int result = detectConnectedComponents(points, 1.0, 2);
    cout << "有效连通分量数：" << result << endl;  // 输出：2
    return 0;
}