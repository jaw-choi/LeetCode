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
        auto l = robSub(root->left);
        auto r = robSub(root->right);
        int skip = max(l.first,l.second) + max(r.first,r.second);
        int take = root->val + l.first + r.first;
        return {skip,take};
    }
    int rob(TreeNode* root) {
        pair<int,int> result;
        result = robSub(root);
        return max(result.first,result.second);
    }
};