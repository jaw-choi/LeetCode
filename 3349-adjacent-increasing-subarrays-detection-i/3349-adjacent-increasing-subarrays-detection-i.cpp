class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int left = 0;
        int right = k;
        int cnt = k-1;
        if(cnt==0)
            return true;
        for(int i=0;i<nums.size()-k-1;i++)
        {
            if(nums[left]<nums[left+1] && nums[right]<nums[right+1])
                cnt--;
            else
                cnt = k-1;
            if(cnt==0)
                return true;
            left++;right++;
        }
        return false;
    }
};