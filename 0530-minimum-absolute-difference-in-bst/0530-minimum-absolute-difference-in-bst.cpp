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
    void helper(TreeNode* root, vector<int>& nums)
    {
        if(!root)
            return;
        nums.push_back(root->val);
        helper(root->left,nums);
        helper(root->right,nums);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> nums;
        int ans = INT_MAX;
        helper(root,nums);
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            int diff = abs(nums[i]-nums[i+1]);
            if(diff < ans)
                ans = diff;
        }
        return ans;
    }
};