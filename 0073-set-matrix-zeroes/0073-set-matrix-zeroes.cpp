class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zeroFirstCol = false;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0)
                zeroFirstCol = true;
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = matrix.size()-1; i >= 0; i--) {
            for (int j = matrix[0].size()-1; j >=1; j--) {
                if(matrix[i][0] == 0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
            if(zeroFirstCol)
                matrix[i][0]=0;
        }
    }
};

/*
        unordered_set<int> xpos;
        unordered_set<int> ypos;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0){
                    xpos.insert(j);
                    ypos.insert(i);
                }
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(xpos.find(j)!=xpos.end() || ypos.find(i)!=ypos.end())
                    matrix[i][j] = 0;
            }
        }

    }
*/