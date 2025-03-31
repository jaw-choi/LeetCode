class Solution {
public:
    void helper(int idx, int curr,const vector<int>& nums, vector<int>& cnt)
    {
        for(int i=idx+1;i<=idx+nums[idx];i++)
        {
            if(i>cnt.size()-1)
                break;
            if(cnt[i] > curr+1)
            {
                cnt[i] = curr + 1;
            }
        }
    }
    int jump(vector<int>& nums) {
        vector<int> cnt(nums.size(),INT_MAX);
        cnt[0]=0;
        for(int i=0;i<cnt.size();i++)
        {
            helper(i,cnt[i],nums,cnt);
        }
        return cnt[cnt.size()-1];
    }
};