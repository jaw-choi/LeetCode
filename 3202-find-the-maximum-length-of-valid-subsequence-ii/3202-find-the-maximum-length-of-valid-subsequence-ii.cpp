class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<int> mod(k,0);
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            int tmp = nums[i]%k;
            mod[tmp]++;
        }
        
        for(auto m : mod)
        {
            ans = max(ans,m);
        }
        return ans+1;
    }
};