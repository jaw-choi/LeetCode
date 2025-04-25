class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i =0;i<nums.size();i++)
        {
            sum += nums[i];
            int diff = sum - k;
            if(mp.find(diff)!=mp.end())
                ans+=mp[diff];
            mp[sum]++;
        }
        return ans;
    }
};