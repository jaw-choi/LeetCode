class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxNum = 0;
        int cnt = 0;
        int curr=0;
        for(auto n:nums)
        {
            maxNum |=n;
        }
        dfs(0,0,maxNum,cnt,nums);
        return cnt;
    }
    void dfs(int idx,int curr,int maxNum,int& cnt, vector<int>& nums)
    {
        if (idx == nums.size()) {
            if (curr == maxNum) cnt++;
            return;
        }
        dfs(idx+1,nums[idx]|curr,maxNum,cnt,nums);
        dfs(idx+1,curr,maxNum,cnt,nums);
    }
};
//3,2,1,5
//011
//010
//001
//101
//5 & 3|2 ||1;