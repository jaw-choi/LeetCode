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
    bool helper(int val, const unordered_map<int,int>& mp)
    {
        if(mp.find(val)!=mp.end())
            return false;
        return true;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dumb = new ListNode();
        ListNode* dumbHead = dumb;
        unordered_map<int,int> mp;
        for(auto& n : nums)
            mp[n]++;
        while(head)
        {
            if(helper(head->val,mp))
            {
                dumb->next = new ListNode(head->val);
                dumb = dumb->next;
            }
            head = head->next;
        }
        return dumbHead->next;
    }
};