#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> index_map;
        for (int i = 0; i < inorder.size(); ++i) {
            index_map[inorder[i]] = i;
        }
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, index_map);
    }

    TreeNode* build(vector<int>& inorder, int in_start, int in_end, vector<int>& postorder, int post_start, int post_end, unordered_map<int, int>& index_map) {
        if (in_start > in_end || post_start > post_end) {
            return nullptr;
        }

        int root_val = postorder[post_end];
        TreeNode* root = new TreeNode(root_val);

        int root_index = index_map[root_val];
        int left_subtree_size = root_index - in_start;

        root->left = build(inorder, in_start, root_index - 1, postorder, post_start, post_start + left_subtree_size - 1, index_map);
        root->right = build(inorder, root_index + 1, in_end, postorder, post_start + left_subtree_size, post_end - 1, index_map);

        return root;
    }
};

// 打印二叉树（中序遍历）
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // 示例输入
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution solution;
    TreeNode* root = solution.buildTree(inorder, postorder);

    // 输出构造的二叉树（中序遍历）
    cout << "Inorder Traversal of Constructed Tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
