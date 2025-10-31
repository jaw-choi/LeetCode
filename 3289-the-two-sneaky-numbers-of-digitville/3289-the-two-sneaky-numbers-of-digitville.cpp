class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto& n : nums)
        {
            mp[n]++;
            if(mp[n]>1)
                ans.push_back(n);
        }
        return ans;
    }
};