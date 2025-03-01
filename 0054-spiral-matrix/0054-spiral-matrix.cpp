class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x = 0;
        int y = 0;
        int dx = 1;
        int dy = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> ans;
        for(int i=0;i<row * col;i++)
        {
            ans.push_back(matrix[y][x]);
            matrix[y][x] = -101;
            if(x+dx<0 || y+dy<0 || y+dy>=row || x+dx>=col || matrix[y+dy][x+dx]==-101){
                int tmp = dx;
                dx = -dy;
                dy = tmp;
            }
            x += dx;
            y += dy;
        }
        return ans;
    }
};