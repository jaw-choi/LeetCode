class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int lgstSide = 0;
        int left,right;
        int cnt = 0;
        for(int i=nums.size()-1;i>=2;i--)
        {
            left = 0;
            right = i-1;
            while(left< right)
            {
                if(nums[left]+nums[right] > nums[i])
                {
                    cnt+=right-left;
                    right--;
                }
                else
                    left++;
            }
        }
        return cnt;
    }
};
//2,3,4,4