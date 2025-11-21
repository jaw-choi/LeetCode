class Solution {
public:
    static int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        for(auto& str : strs)
        {

            int zeroes = ranges::count(str,'0');
            int ones = str.size() - zeroes;
            for(int i=m;i>=zeroes;i--){
                for(int j=n;j>=ones;j--){
                    dp[i][j] = max(dp[i][j],dp[i-zeroes][j-ones]+1);
                }
            }
        }
        return dp[m][n];
    }
};
static const auto init = []() noexcept {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();