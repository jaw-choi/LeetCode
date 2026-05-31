class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto& n : nums)
            mp[n]++;
        for(auto& m : mp){
            if(m.second == nums.size()/2)
                return m.first;
        }
        return 0;
    }
};