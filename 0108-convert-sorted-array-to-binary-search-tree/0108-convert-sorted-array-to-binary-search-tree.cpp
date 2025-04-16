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
    TreeNode* helper(int start,int end,vector<int>& nums)
    {
        if(start>end)
            return nullptr;
        int mid = start + (end-start)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = helper(start,mid-1,nums);
        node->right = helper(mid+1,end,nums);
        return node;
    }


    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        // TreeNode* node = new TreeNode();
        // helper(0,nums.size()-1,nums);
        // while(left<=right)
        // {
        //     int mid = left + (right-left)/2;
        //     helper(mid,);
        // }
        return helper(0,nums.size()-1,nums);
    }
};