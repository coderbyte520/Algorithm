/**
 * 《图解算法》配套代码 - 高阶DP
 * 文件: ch20_advanced_dp/03_tree_dp_bonus.cpp
 * 难度: 见书稿对应章节标注
 *
 * 编译运行:
 *   g++ -std=c++17 -o 03_tree_dp_bonus 03_tree_dp_bonus.cpp
 *   ./03_tree_dp_bonus
 */

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

pair<int, int> dfs(TreeNode* node) {
    if (!node) return {0, 0};
    auto left = dfs(node->left);
    auto right = dfs(node->right);
    int award = node->val + left.second + right.second;
    int noAward = max(left.first, left.second) + max(right.first, right.second);
    return {award, noAward};
}

int maxBonus(TreeNode* root) {
    auto result = dfs(root);
    return max(result.first, result.second);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    cout << "最大年终奖金额：" << maxBonus(root) << endl;
    return 0;
}