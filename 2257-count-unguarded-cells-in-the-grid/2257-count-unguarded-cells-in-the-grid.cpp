class Solution {
public:
vector<int> dirY = {-1,0,1,0};
vector<int> dirX = {0,1,0,-1};
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int ans = 0;
        vector<vector<int>> grid(m,vector<int>(n,0));
        for(auto& g : guards)
        {
            grid[g[0]][g[1]]=1;
        }
        for(auto& w : walls)
        {
            grid[w[0]][w[1]]=1;
        }
        set<vector<int>> s(walls.begin(),walls.end());
        set<vector<int>> gs(guards.begin(),guards.end());
        for(auto& g : guards)
        {
            int gy = g[0];
            int gx = g[1];

            for(int i=0;i<4;i++)
            {
                int ny = gy + dirY[i];
                int nx = gx + dirX[i];
                while(ny>=0 && ny <m && nx >=0 && nx <n)
                {
                    if(s.find({ny,nx})!=s.end())
                        break;
                    if(gs.find({ny,nx})!=gs.end())
                        break;                    
                    grid[ny][nx]=1;
                    ny += dirY[i];
                    nx += dirX[i];
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                    ans++;
            }
        }
        return ans;
    }
};