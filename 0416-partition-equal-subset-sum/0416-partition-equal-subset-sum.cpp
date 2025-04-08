class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int curr = 0;
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)
            return false;

        int n = nums.size();
        int target = sum/2;
        vector<bool> dp(target+1,false);
        dp[0]=true;

        for(auto num : nums)
        {
            for(int i = target;i>=num;--i)
            {
                dp[i] = dp[i] || dp[i-num];
                if(dp[target])
                    return true;
            }
            
        }
        for(auto d : dp)
                cout << d << " ";
            cout << endl;
        return false;
    }
};
//1,5,5,11
//1,6,11,22
//1,3,6,11
//1,2,3,4,5,9,10
//1,3,6,1