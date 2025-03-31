class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump = 1;
        bool ans = true;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]>=jump){
                ans = true;
                jump = 1;
            } 
            else{
                ans = false;
                jump++;
            }
            
        }
        return ans;
    }
};