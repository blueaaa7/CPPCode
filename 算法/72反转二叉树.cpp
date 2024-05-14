
//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


#include <algorithm>
using namespace std;
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)return root;
        TreeNode* cur = root;
        swap(cur->left,cur->right);
        invertTree(cur->left);
        invertTree(cur->right);
        return root;
    }
};