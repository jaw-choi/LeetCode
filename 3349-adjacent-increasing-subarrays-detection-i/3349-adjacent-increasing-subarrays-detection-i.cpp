class Solution {
public:
    bool check(const vector<int>& nums, int idx,int k)
    {
        for(int i=idx;i<idx+k-1;i++)
        {
            if(nums[i]>=nums[i+1])
                return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int left = 0;
        int right = left + k;
        int n = nums.size();
        int limit = n-k;
        while(right <= limit)
        {
            for(int i=0;i<3;i++)
            {
                if(check(nums,left,k) && check(nums,right,k))
                    return true;
            }
            left++;right++;
        }
        return false;
    }
};