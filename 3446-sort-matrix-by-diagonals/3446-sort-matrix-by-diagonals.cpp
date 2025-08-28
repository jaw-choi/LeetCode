class Solution {
public:
    void helper(int n, int y,int x,bool flag, vector<vector<int>>& grid)
    {
        vector<int> tmp;
        int startY = y;
        int startX = x;
        while(y<n && x<n){
            tmp.push_back(grid[y++][x++]);
        }
        if(flag)
            sort(tmp.begin(),tmp.end());
        else
            sort(tmp.rbegin(),tmp.rend());
        y = startY;
        x = startX;
        int i=0;
        while(y<n && x<n){
            grid[y++][x++] = tmp[i++];
        }

        for(auto& t : tmp)
            cout <<t<<" ";
        cout << endl;
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans;
        for(int j=n-1;j>0;j--)
        {
            helper(n,0,j,true,grid);
        }        
        for(int i=0;i<n;i++)
        {
            helper(n,i,0,false,grid);
        }        
        return grid;
    }
};