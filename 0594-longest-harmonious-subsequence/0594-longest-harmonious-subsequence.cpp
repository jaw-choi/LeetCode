class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        int cnt;
        unordered_map<int,int> mp;
        for(auto n : nums)
            mp[n]++;

        for(int i = 0;i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end() && mp.find(nums[i]+1)!=mp.end()){
                ans = max(ans,mp[nums[i]]+mp[nums[i]+1]);

               }
        }
        return ans;
    }
};//1,2,2,2,3,3,5,7