class Solution {
public:
    void helper(int& ans, int idx, int curr, const vector<int>& nums)
    {
        for(int i=idx+1;i<nums.size();i++)
        {
            ans+= (curr ^ nums[i]);
            helper(ans,i,curr ^ nums[i],nums);
        }
    }
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=nums[i];
            helper(ans,i,nums[i],nums);
        }
        return ans;
    }
};