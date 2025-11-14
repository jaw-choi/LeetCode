class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n+1,vector<int>(n+1,0));
        vector<vector<int>> answer(n,vector<int>(n,0));
        for(int i=0;i<queries.size();i++)
        {
            int r1 = queries[i][0];
            int c1 = queries[i][1];
            int r2 = queries[i][2];
            int c2 = queries[i][3];
            diff[r1][c1] += 1;
           diff[r1][c2 + 1] -= 1;
            diff[r2 + 1][c1] -= 1;
             diff[r2 + 1][c2 + 1] += 1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                int up = (i>0) ? answer[i-1][j] : 0;
                int left = (j>0) ? answer[i][j-1] : 0;
                int diag = (i>0&&j>0) ? answer[i-1][j-1] : 0;
                answer[i][j] = diff[i][j] + (up + left - diag);
            }
        }
        return answer;
    }
};