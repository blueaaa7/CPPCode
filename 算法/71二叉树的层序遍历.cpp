

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

#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return res;
        queue<TreeNode*> que;
        TreeNode* cur = root;
        que.push(cur);
        while(!que.empty())
        {
            int curLen = que.size();
            res.push_back(vector<int>());
            for(int i = 0; i < curLen; i++)
            {
                auto tmp = que.front();
                que.pop();
                res.back().push_back(tmp->val);
                if(tmp->left)que.push(tmp->left);
                if(tmp->right)que.push(tmp->right);
            }
        }
        return res;
    }
};