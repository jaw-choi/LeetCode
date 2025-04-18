class Solution {
public:
    string countAndSay(int n) {
        vector<string> dp(n+1,"");
        dp[1]="1";
        for(int i=2;i<=n;i++)
        {
            int idx = 0;
            for(int j=0;j<dp[i-1].size();)
            {
                char num = dp[i-1][idx];
                int cnt = 0;
                while(j<dp[i-1].size()&&dp[i-1][j]==num){
                    j++;
                    cnt++;
                }
                if(j<dp[i-1].size())
                    idx = j;
                //cout << cnt <<" "<< num <<" "<<j<<endl;
                dp[i].push_back(cnt+'0');
                dp[i].push_back(num);
                //cout<<dp[i]<<endl;
            }
        }
        return dp[n];        
    }
};