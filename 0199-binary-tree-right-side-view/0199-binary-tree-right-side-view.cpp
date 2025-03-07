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
    void helper(int level, TreeNode* node, vector<int>& ans)
    {
        if(!node)
            return;
        if(level>=ans.size())
        {
            ans.push_back(node->val);
        }
        else
        {
            ans[level] = node->val;
        }
        helper(level+1,node->left,ans);
        helper(level+1,node->right,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        helper(0,root,ans);
        return ans;
    }
};