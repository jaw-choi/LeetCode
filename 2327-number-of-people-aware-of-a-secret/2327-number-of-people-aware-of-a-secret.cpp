class Solution {
public:
    int mod = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int ans = 0;
        vector<int> dp(n+1,0);
        dp[1]=1;
        long long share = 0;
        for(int day = 2;day<=n;day++)
        {
            if(day-delay>0)//share
            {
                share = (share + dp[day-delay]+mod)%mod;
            }
            if(day-forget > 0)//forget
            {
                share = (share - dp[day-forget]+mod)%mod;
            }
            dp[day] = share;
        }
        long long know = 0;
        for(int i = n - forget + 1;i<=n;i++)
        {
            know = (know + dp[i])%mod;
        }
        return know;
    }
};