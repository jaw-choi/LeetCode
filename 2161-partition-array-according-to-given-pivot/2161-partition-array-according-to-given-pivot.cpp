class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        vector<int> prev;
        vector<int> curr;
        vector<int> next;
        for(const auto& n : nums)
        {
            if(n < pivot)
                prev.push_back(n);
            else if(n==pivot)
                curr.push_back(n);
            else
                next.push_back(n);
        }
        for(const auto& n : prev)
            ans.push_back(n);
        for(const auto& n : curr)
            ans.push_back(n);
        for(const auto& n : next)
            ans.push_back(n);
        
        return ans;

    }
};