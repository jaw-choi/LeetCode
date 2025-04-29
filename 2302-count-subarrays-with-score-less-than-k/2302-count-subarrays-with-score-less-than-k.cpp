class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0;
        long long ans = 0;
        for(int left=0,right=0;right<nums.size();right++)
        {
            sum+=nums[right];
            while(left<=right && sum*(right-left+1)>=k){
                sum-=nums[left];
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};