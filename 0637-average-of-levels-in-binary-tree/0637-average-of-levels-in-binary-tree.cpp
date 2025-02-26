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
    void helper(long level, long cnt, TreeNode* root, map<long,pair<long,long>>& mp)
    {
        if(!root)
            return;
        mp[level].first++;
        mp[level].second+=root->val;
        helper(level+1,0,root->left,mp);
        helper(level+1,0,root->right,mp);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        // if(!root)
        //     return;
        vector<double> ans;
        map<long,pair<long,long>> mp;
        helper(0,0,root,mp);//level, cnt, num
        for(auto m : mp)
        {
            ans.push_back(m.second.second / (double)m.second.first);
        }
        return ans;
    }
};