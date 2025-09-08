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
    int ans = INT_MAX;
    void dfs(TreeNode* root, int height)
    {
        if(!root)
            return;
        if(root)
        {
            if(!root->left && !root->right){
                ans = min(ans,height);
                return;
            }
            dfs(root->left,height+1);
            dfs(root->right,height+1);
        }

    }
    int minDepth(TreeNode* root) {
        dfs(root,1);
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};