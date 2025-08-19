class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long cnt = 0;
        int n = nums.size();
        //vector<long long> dp(n+1,0);
        // for(int i=1;i<=n;++i)
        // {
        //     dp[i] = i + dp[i-1];
        // }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                cnt++;
            else{
                ans += cnt*(cnt+1)/2;
                cnt = 0;
            }
        }
        ans += cnt*(cnt+1)/2;
        return ans;
    }
};
//0,0,0,0
/*
7
dp[i] = i + dp[i-1]
0:0
1:1
2:3
3:6
4:10
5:15

5:1
4:2
3:3
2:4
1:5
*/