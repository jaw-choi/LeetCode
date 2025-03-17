class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i+=2)
        {
            if(nums[i]!=nums[i+1])
                return false;
        }
        return true;
        // unordered_map<int,int> mp;
        // for(const auto& n : nums)
        // {
        //     mp[n]++;
        // }
        // for(auto m : mp)
        // {
        //     if(m.second%2!=0)
        //         return false;
        // }
        // return true;
    }
};