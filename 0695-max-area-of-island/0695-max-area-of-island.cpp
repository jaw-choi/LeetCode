class Solution {
public:
    vector<int> dirY = {-1,1,0,0};
    vector<int> dirX = {0,0,-1,1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        int ans = 0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        
        for(int y=0;y<n;y++)
        {
            for(int x=0;x<m;x++)
            {
                if(grid[y][x]==0) continue;
                if(visited[y][x]==1) continue;
                visited[y][x] = 1;
                q.push({y,x});
                cnt = 1;
                while(!q.empty())
                {
                    auto [r,c] = q.front();
                    q.pop();

                    for(int i=0;i<4;i++)
                    {
                        int ny = r + dirY[i];
                        int nx = c + dirX[i];
                        if(ny<0 || ny>=n || nx <0 || nx>=m) continue;
                        if(grid[ny][nx]==0) continue;
                        if(visited[ny][nx]) continue;
                        visited[ny][nx]=1;
                        cnt++;
                        q.push({ny,nx});
                    }
                }
                //cout << cnt << endl;
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};