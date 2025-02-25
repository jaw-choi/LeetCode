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
    void change(TreeNode* root)
    {
        if(!root)
            return;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        change(root->left);
        change(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        change(root);
        
        return root;
    }
};