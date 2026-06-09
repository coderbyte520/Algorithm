/**
 * 《图解算法》配套代码 - 栈与队列
 * 文件: ch11_stack_queue/01_valid_parentheses.cpp
 * 难度: 🟢简单
 *
 * 编译运行:
 *   g++ -std=c++17 -o valid_parentheses 01_valid_parentheses.cpp
 *   ./valid_parentheses
 */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            st.pop();
            if (c == ')' && top != '(') return false;
            if (c == ']' && top != '[') return false;
            if (c == '}' && top != '{') return false;
        }
    }
    return st.empty();
}

int main() {
    cout << boolalpha;
    cout << isValid("()[]{}") << endl; // true
    cout << isValid("([)]") << endl; // false
    return 0;
}
