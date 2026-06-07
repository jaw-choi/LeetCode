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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* head = new TreeNode();
        unordered_map<int,TreeNode*> mp;
        unordered_set<int> children;

        for(const auto& d : descriptions)
        {
            int parent = d[0];
            int child = d[1];
            bool isLeft = d[2];

            if(mp.count(parent)==0)
            {
                mp[parent] = new TreeNode(parent);
            }
            if(mp.count(child)==0)
            {
                mp[child] = new TreeNode(child);
            }

            if(isLeft)
            {
                mp[parent]->left = mp[child];
            }
            else
            {
                mp[parent]->right = mp[child];
            }
            children.insert(child);
        }

        for(auto& entry:mp)
        {
            auto& val = entry.first;
            auto& node = entry.second;
            if(children.find(val)==children.end())
                return node;
        }
        return nullptr;



    }
};