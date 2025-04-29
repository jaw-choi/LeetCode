class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int n = nums.size();
        int target = *max_element(nums.begin(), nums.end());
        int cnt = 0;
        for (int left = 0, right = 0; right < n; right++) {
                if (nums[right] == target){
                    cnt++;
                    while(cnt>=k){
                        ans+=n-right;
                        if(nums[left]==target)
                            cnt--;
                        left++;
                    }
                }
        }
        return ans;
    }
};