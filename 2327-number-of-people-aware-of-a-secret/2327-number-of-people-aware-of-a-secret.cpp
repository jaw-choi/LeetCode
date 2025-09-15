class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod = 1e9+7;
        long long answer = 0;
        vector<int> dp(n+1,0);
        dp[1]=1;
        long long share = 0;
        for(int today=2;today<=n;today++)
        {
            if(today - delay >0)
            {
                share = (share + dp[today - delay] + mod) % mod;
           // cout << "+"<<today << " : " << share << " " << dp[today-delay]<<endl;
            }
            if(today - forget > 0)
            {
                share = (share - dp[today - forget] + mod)%mod;
            //cout << "-"<<today << " : " << share << " " << dp[today-forget]<<endl;
            }
            dp[today] = share;
            //cout <<"dp"<<dp[today]<<endl;
        }
        for(int i=n-forget+1;i<=n;i++){
            answer = (answer + dp[i])%mod;
        }

        return answer;
    }
};