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

class Solution{
    public:
        int sumOfLeftLeaves(TreeNode* root)
        {
            if(root == nullptr) return 0;
            int left_sum = sumOfLeftLeaves(root->left);
            if(root->left && root->left->left ==nullptr && root->left->right == nullptr)
            {
                left_sum += root->left->val;
            }          
            int right_sum = sumOfLeftLeaves(root->right);
            return left_sum+right_sum;
        }
};