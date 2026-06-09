/**
 * 《图解算法》配套代码 - 综合拆解
 * 文件: ch21_comprehensive/03_command_validate.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 03_command_validate 03_command_validate.cpp
 *   ./03_command_validate
 */

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int longestValidCmd_stack(string cmd) {
    stack<int> st;
    st.push(-1);
    int maxLen = 0;
    for (int i = 0; i < cmd.size(); i++) {
        if (cmd[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            } else {
                maxLen = max(maxLen, i - st.top());
            }
        }
    }
    return maxLen;
}