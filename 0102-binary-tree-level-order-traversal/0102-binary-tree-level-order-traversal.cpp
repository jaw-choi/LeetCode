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
    void helper(int level,TreeNode* node, map<int,vector<int>>& mp)
    {
        if(!node)
            return;
        mp[level].push_back(node->val);
        helper(level+1,node->left,mp);
        helper(level+1,node->right,mp);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<int>> mp;//level,nodes

        helper(0,root,mp);
        for(auto m : mp)
        {
            ans.push_back(m.second);
        }
        return ans;
    }
};