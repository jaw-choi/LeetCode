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
    pair<int,int> robSub(TreeNode* root)
    {
        if(!root) return {0,0}; 
        auto left = robSub(root->left);
        auto right = robSub(root->right);
        int skip = max(left.first,left.second) + max(right.first,right.second);
        int take = root->val + left.first + right.first;
        return {skip,take};
    }
    int rob(TreeNode* root){
        pair<int,int> result = robSub(root);
        return max(result.first,result.second);
    }
};
