class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        int left = 0;
        int right = nums.size()-1;
        if(nums.size()==1)
            return nums[0];
        while(left<=right)
        {
            int mid = left + (right - left)/2;
            if(mid%2==0){
                if(nums[mid]==nums[mid+1]){
                    left = mid + 1;
                }
                else{
                    ans = nums[mid];
                    right = mid - 1;
                }
            }
            else{
                if(nums[mid]==nums[mid-1]){
                    left = mid + 1;
                }
                else{
                    ans = nums[mid];
                    right = mid - 1;
                }
            }
        }
        return ans;
    }
};