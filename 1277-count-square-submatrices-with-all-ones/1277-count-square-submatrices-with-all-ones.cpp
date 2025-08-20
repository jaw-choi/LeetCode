class Solution {
public:
    int helper(vector<vector<int>>& matrix)
    {
        int ans = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++)
            {
                ans+=matrix[i][j];
            }
        }
        return ans;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int side = min(m,n);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==1)
                    matrix[i][j] = min(matrix[i-1][j-1],min(matrix[i][j-1],matrix[i-1][j])) + 1;
            }
        }
        return helper(matrix);
    }
};
