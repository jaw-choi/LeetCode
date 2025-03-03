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
    void helper(TreeNode* root, int level,map<int,vector<int>>& mp)
    {
        if(!root)
            return;
        
        mp[level].push_back(root->val);
        
        helper(root->left,level +1,mp);
        helper(root->right,level +1,mp);        
    }


    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        map<int,vector<int>> mp;
        helper(root,0,mp);

        for(auto m : mp)
        {
            ans.push_back(m.second);
        }
        for(int i=0;i<ans.size();i++)
        {
            if(i%2==1)
                reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};