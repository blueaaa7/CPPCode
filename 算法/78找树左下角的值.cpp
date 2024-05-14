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
    int findBottomLeftValue(TreeNode* root) {
        if(root == nullptr)return 0;
        int depth = 0;
        int curVal,curDepth;
        dfs(root,0,curVal,curDepth);
        return curVal;
    }

    void dfs(TreeNode* root,int depth, int &curVal, int &curDepth)
    {

        if(root == nullptr) return;
        depth++;
        dfs(root->left,depth,curVal,curDepth);
        dfs(root->right,depth,curVal,curDepth);
        if(depth > curDepth)
        {
            curVal = root->val;
            curDepth = depth;
        }
    }
};