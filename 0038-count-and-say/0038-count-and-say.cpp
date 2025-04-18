class Solution {
public:
    string countAndSay(int n) {
        vector<string> dp(n+1,"");
        dp[1]="1";
        int cnt = 0;
        for(int i=2;i<=n;i++)
        {
            string& prev = dp[i-1];
            string curr;
            for(int j=0,start=0;j<=prev.size();++j)
            {
                if(j==prev.size()||prev[j]!=prev[start])
                {
                    int cnt = j-start;
                    curr += to_string(cnt)+prev[start];
                    start = j;
                }
            }
            dp[i]=curr;
        }
        return dp[n];        
    }
};