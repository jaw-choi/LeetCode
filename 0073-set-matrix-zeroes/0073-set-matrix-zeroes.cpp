class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
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
};