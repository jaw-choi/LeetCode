class Solution {
public:
    int ans = 0;
    vector<int> dirY = {0,1};
    vector<int> dirX = {1,0};
    void dfs(int y, int x, int m, int n,int sum, int k, vector<vector<int>>& visited,vector<vector<int>>& grid)
    {
        if(y==m-1 && x==n-1){
            if(sum%k==0){
                ans++;
                return;
            }
        }
        for(int i=0;i<2;i++)
        {
            int ny = y + dirY[i];
            int nx = x + dirX[i];
            if(ny>=m || nx >=n) continue;
            if(visited[ny][nx]==1) continue;
            visited[ny][nx] = 1;
            dfs(ny,nx,m,n,sum+grid[ny][nx],k,visited,grid);
            visited[ny][nx] = 0;
        }
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {

        int mod = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();
        int val = grid[0][0];
        auto dp = vector(m + 1, vector(n + 1, vector<long long>(k)));
        //auto dp = vector(m + 1, vector(n + 1, vector<long long>(k)));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==1 && j==1){
                    dp[i][j][grid[0][0]%k] = 1;
                    continue;
                }

                val = grid[i-1][j-1] % k;
                for(int r = 0; r < k; r++)
                {
                    int prevMod = (r - val + k) % k;
                    dp[i][j][r] = (dp[i-1][j][prevMod] + dp[i][j-1][prevMod]) % mod;
                }
            }
        }
        return dp[m][n][0];
    }
};