class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        bool flag = false;
        int minGrid = 0;
        int minN = 0;
        int minM = 0;
        int maxGridN = 0;
        int maxGridM = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1){
                    if(!flag){
                        flag = true;
                        minGrid = min(i,j);
                        minN = i;
                        minM = j;
                    }
                    maxGridN = i;
                    maxGridM = j;
                }
                
            }
        }
        cout << minGrid << " " << minGrid << " " << maxGridN << " " << maxGridM <<endl;
        if(maxGridN==0 || maxGridM ==0){
            if(grid[minGrid][minGrid]==0){
            if(maxGridN!=0)
                return maxGridN;
            if(maxGridM!=0)
                return maxGridM;
            }
        }
        return (maxGridN-minGrid+1)*(maxGridM-minGrid+1);
    }
};