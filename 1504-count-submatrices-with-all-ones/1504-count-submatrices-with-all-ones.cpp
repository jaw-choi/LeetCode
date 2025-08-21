class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(mat[i][j]>=1)
                    mat[i][j] += mat[i][j-1];
            }
        }

        for(int j=0;j<m;j++)
        {
            for(int i=1;i<n;i++)
            {
                if(mat[i][j]>=1)
                    mat[i][j] += mat[i-1][j];
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans += mat[i][j];                
            }
        }

        return ans;
    }
};
