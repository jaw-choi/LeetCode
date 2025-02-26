/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void connectNext(Node* root)
    {
        if(root->left)
        {
            if(root->right)
            {
                root->left->next = root->right;
            }
            else
            {
                root->left->next = nullptr;
            }
        }
        Node* l = root->left;
        Node* r = root->right;
        if(l){
            connectNext(l);
            connectNext(l->left,l->right);
        }
        if(r){
            connectNext(r);
            connectNext(r->left,r->right);
        }
    }
    void connectNext(Node* l, Node* r)
    {
        if(l)
        {
            if(l->right)
            {
                if(r && r->left)
                {
                    l->right->next = r->left;
                }
                else
                {
                    if(r && r->right)
                    {
                        l->right->next = r->right;
                    }
                    else
                        l->right->next = nullptr;
                }
            }
            else if(l->left)
            {
                if(r && r->left)
                {
                    l->left->next = r->left;
                }
                else
                {
                    if(r && r->right)
                    {
                        l->left->next = r->right;
                    }
                    else
                        l->left->next = nullptr;
                }
            }

        }
    }
    Node* connect(Node* root) {
        if(!root)
            return root;
        connectNext(root);
        connectNext(root->left,root->right);
        return root;
    }
};