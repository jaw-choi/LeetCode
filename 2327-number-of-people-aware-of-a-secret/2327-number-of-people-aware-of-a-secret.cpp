class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod = 1e9 + 7;
        int answer = 0;
        long long share=0;
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int today=1;today<=n;today++)
        {
            if(today-delay>0)
            {
                share = (share + dp[today-delay] + mod) % mod;
            }
            if(today-forget>0)
            {
                share = (share - dp[today-forget] + mod) % mod;
            }
            if(today>1)
                dp[today] = (share)%mod;
            cout << today << " " << dp[today] << " " << share << endl;
        }
        for(int i=n-forget+1;i<=n;i++)
        {
            answer = (answer + dp[i]) % mod;
        }
        return answer;
    }
};