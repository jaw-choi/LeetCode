class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int num = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                num++;
            
            if(num%5==0)
                ans.push_back(true);
            else
                ans.push_back(false);
            num <<= 1;
            num %= 10;
        }
        return ans;
    }
};