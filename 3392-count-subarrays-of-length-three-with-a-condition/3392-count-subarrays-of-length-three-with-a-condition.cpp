class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0;
        for(int i=2;i<nums.size();i++)
        {
            if(nums[i-1]%2!=0) continue;
            if(nums[i]+nums[i-2] == nums[i-1]/2)
                ans++;
        }
        return ans;
    }
};