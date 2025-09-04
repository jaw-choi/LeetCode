class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = 1;
        int right = INT_MAX;
        int cnt = 0;
        int ans = 0;

        while(left<=right)
        {
            int mid = (right-left)/2 + left;
            cnt=0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i] <= mid){
                    cnt++;
                    i++;
                }
            }
            if(cnt >= k){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};