/**
 * 《图解算法》配套代码 - 二叉树
 * 文件: ch12_binary_tree/01_tree_traversal.cpp
 * 难度: 🟢简单
 *
 * 编译运行:
 *   g++ -std=c++17 -o tree_traversal 01_tree_traversal.cpp
 *   ./tree_traversal
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 前序遍历：根 -> 左 -> 右
void preorder(TreeNode* root, vector<int>& res) {
    if (!root) return;
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
}

// 中序遍历：左 -> 根 -> 右
void inorder(TreeNode* root, vector<int>& res) {
    if (!root) return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}

// 后序遍历：左 -> 右 -> 根
void postorder(TreeNode* root, vector<int>& res) {
    if (!root) return;
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
}

int main() {
    // 构建二叉树:    1
    //                / \
    //               2   3
    //              / \
    //             4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    vector<int> res;
    
    preorder(root, res);
    cout << "Preorder: ";
    for (int x : res) cout << x << " ";
    cout << endl;
    
    res.clear();
    inorder(root, res);
    cout << "Inorder: ";
    for (int x : res) cout << x << " ";
    cout << endl;
    
    res.clear();
    postorder(root, res);
    cout << "Postorder: ";
    for (int x : res) cout << x << " ";
    cout << endl;
    
    return 0;
}
