class Solution {
public:
    string helper(const string& str)
    {
        string tmp="";
        for(auto s : str)
        {
            if(s=='z')
                tmp += 'a';
            else
                tmp += (s+1);
        }
        return tmp;
    }
    char kthCharacter(int k) {
        string str = "a";
        int cnt = log2(k) + 1;
        vector<string> dp(cnt+1,"");
        dp[0] = "a";
        for(int i=1;i<cnt+1;i++)
        {
            dp[i] = dp[i-1];
            dp[i] += helper(dp[i-1]);
            cout <<dp[i]<<endl;
        }

        return dp[cnt][k-1];
    }
};