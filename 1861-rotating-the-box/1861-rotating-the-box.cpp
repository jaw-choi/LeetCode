class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        int mark;
        for(int i=0;i<n;i++)
        {
            mark = m-1;
            for(int j=m-1;j>=0;j--)
            {
                if(boxGrid[i][j]=='.'){
                    continue;
                }
                else if(boxGrid[i][j]=='*'){
                    mark = j-1;
                }
                else{
                    if(mark==j){
                        mark = mark - 1;
                        continue;
                    }
                    boxGrid[i][j] = '.';
                    if(mark>=0)
                        boxGrid[i][mark] = '#';
                    mark = mark - 1;
                }
            }
        }

        vector<vector<char>> ans(m,vector<char>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=n-1;j>=0;j--)
            {
                ans[i][n-1-j] = boxGrid[j][i];
            }
        }

        return ans;
    }
};