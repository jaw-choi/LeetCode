class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum,rightSum;
        int leftCurr = 0;
        int rightCurr = accumulate(nums.begin(),nums.end(),0) - nums[0];
        for(int i=0;i<nums.size();i++)
        {
            leftSum.push_back(leftCurr);
            rightSum.push_back(rightCurr);
            leftCurr+=nums[i];
            if(i!=n-1)
                rightCurr-=nums[i+1];
        }
        vector<int> ans(n);
        for(int i=0;i<nums.size();i++)
            ans[i] = abs(leftSum[i]-rightSum[i]);
        return ans;
    }
};