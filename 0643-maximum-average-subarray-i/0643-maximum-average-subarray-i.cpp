class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        double tmp = 0;
        if(k==1)
            return *max_element(nums.begin(),nums.end());

        for(int i=0;i<k;i++)
            tmp+=nums[i];
        sum = tmp;
        for(int i=0;i<nums.size()-k;i++)
        {
            tmp = tmp - nums[i]+nums[i+k];
            sum = max(sum,tmp);
        }

        return sum/k;
    }
};