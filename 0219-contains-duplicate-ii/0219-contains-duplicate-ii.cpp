class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                if(j-i>k)
                    break;
                if(i!=j){
                    if(nums[i]==nums[j]){
                        if(abs(i-j)<=k)
                            return true;
                    }
                }
            }
        }
        return false;
    }
};