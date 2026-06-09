/**
 * 《图解算法》配套代码 - 滑动窗口
 * 文件: ch18_sliding_window/02_sensor_peak.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 02_sensor_peak 02_sensor_peak.cpp
 *   ./02_sensor_peak
 */

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> slidingMax(vector<int>& readings, int k) {
    deque<int> dq;
    vector<int> res;
    
    for (int i = 0; i < readings.size(); i++) {
        while (!dq.empty() && dq.front() < i - k + 1)
            dq.pop_front();
        while (!dq.empty() && readings[dq.back()] < readings[i])
            dq.pop_back();
        dq.push_back(i);
        
        if (i >= k - 1)
            res.push_back(readings[dq.front()]);
    }
    return res;
}

int main() {
    vector<int> readings = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> res = slidingMax(readings, k);
    cout << "传感器峰值：";
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}