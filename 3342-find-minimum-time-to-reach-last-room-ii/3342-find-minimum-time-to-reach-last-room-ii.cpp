class Solution {
public:
    vector<int> dirY = {-1, 1, 0, 0};
    vector<int> dirX = {0, 0, -1, 1};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        int inf = INT_MAX;
        vector<vector<int>> distance(n, vector<int>(m, inf));
        vector<vector<int>> visited(n, vector<int>(m, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            q;

        q.push({0, 0, 0}); // d,y,x
        while (!q.empty()) {
            vector<int> states = q.top();
            q.pop();
            int d = states[0];
            int y = states[1];
            int x = states[2];
            if (visited[y][x])
                continue;
            visited[y][x] = 1;
            for (int i = 0; i < 4; i++) {
                int ny = y + dirY[i];
                int nx = x + dirX[i];
                if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
                    int nd = 0;
                    if ((ny + nx) % 2 == 1)
                        nd = max(d, moveTime[ny][nx]) + 1;
                    else
                        nd = max(d, moveTime[ny][nx]) + 2;
                    if (nd < distance[ny][nx]) {
                        distance[ny][nx] = nd;
                        q.push({nd, ny, nx});
                    }
                }
            }
        }

        return distance[n - 1][m - 1];
    }
};