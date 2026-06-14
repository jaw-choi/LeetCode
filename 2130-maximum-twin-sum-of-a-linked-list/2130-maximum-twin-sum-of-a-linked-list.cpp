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
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* tmp = head;
        while(tmp)
        {
            n++;
            tmp = tmp->next;
        }
        vector<int> v(n/2,0);
        tmp = head;
        int cnt = 0;
        while(tmp)
        {
            if(cnt < n/2)
            {
                v[cnt] += tmp->val;
            }
            else
            {
                v[n-1-cnt] += tmp->val;
            }
            cnt++;
            tmp = tmp->next;
        }
        int ans = 0;
        for(auto num : v)
        {
            //cout << num << endl;
            if(num > ans)
                ans = num;
        }
        return ans;
    }
};