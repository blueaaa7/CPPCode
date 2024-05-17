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
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        unordered_map<int,int> index_map;
        for(int i = 0; i < nums.size(); ++i)
        {
            index_map[nums[i]] = i;
        }   
        return build(nums,0,nums.size()-1,index_map);

    }

    TreeNode* build(vector<int>& nums,int start, int end,unordered_map<int,int>& index_map)
    {
        if(start > end)return nullptr;
        auto max_it = max_element(nums.begin() + start,nums.begin() + end + 1);
        int maxNum = *max_it;
        int maxIndex = index_map[maxNum];
        TreeNode* root = new TreeNode(maxNum);
        root->left = build(nums,start,maxIndex-1,index_map);
        root->right = build(nums,maxIndex+1,end,index_map);
        return root;        
    }
};