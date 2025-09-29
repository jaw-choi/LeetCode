class Solution {
public:
    // 재귀 + 메모이제이션
    int helper(int i, int j, vector<int>& values, vector<vector<int>>& dp) {
        if (j - i < 2) return 0; // 삼각형을 만들 수 없는 구간

        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int cost = helper(i, k, values, dp) 
                     + helper(k, j, values, dp) 
                     + values[i] * values[j] * values[k];
            ans = min(ans, cost);
        }

        return dp[i][j] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(0, n - 1, values, dp);
    }
};
