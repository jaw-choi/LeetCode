class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int left=0;
        int right=1;
        int ans = 0;
        for(int i=nums.size()-3;i>=0;i--)
        {
            if(nums[i]+nums[i+1] > nums[i+2])
                return nums[i]+nums[i+1]+nums[i+2];
        }
        return ans;
    }//2,3,3,4
};