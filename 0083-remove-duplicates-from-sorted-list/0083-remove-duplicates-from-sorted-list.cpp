/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = head;
        ListNode* tmp = head;
        while(tmp)
        {
            while(tmp->val==ptr->val){
                ptr = ptr->next;
                if(!ptr)
                    break;
            }
            tmp->next = ptr;
            tmp = tmp->next;
        }
        return head;
    }
};