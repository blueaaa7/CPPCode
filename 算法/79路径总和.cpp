/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,targetSum);
    }

    bool dfs(TreeNode * root,int rest)
    {
        if(root == nullptr)
        {
            return false;
        }
        if(root->val == rest && root->left == nullptr && root->right == nullptr)
        {
            return true;
        }
         return dfs(root->left,rest - root->val) || dfs(root->right,rest - root->val);
    }
};