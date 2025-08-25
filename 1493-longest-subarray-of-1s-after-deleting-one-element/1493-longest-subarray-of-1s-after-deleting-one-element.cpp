class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int delCnt = 1;
        int cnt = 0;
        int n = nums.size();
        int left=0, right = 0;
        for(right;right<n;right++)
        {
            if(nums[right]==0){
                if(delCnt==1)
                    delCnt--;
                else{
                    while(nums[left]==1 && left<n-1)
                        left++;
                    left++;
                }
            }
            cnt = max(cnt,right - left + 1);
            //cout << right << " " << left << " " << cnt <<" "<<delCnt<< endl;
        }

        return cnt - 1;
    }
};