class Solution {
public:
bool checkRow(int y, int x, map<char,int>& mp,const vector<vector<char>>& board)
{
    for(int i=0;i<9;i++)
    {
        if(board[y][i]=='.') continue;
        if(mp.find(board[y][i])==mp.end())
            mp[board[y][i]]++;
        else
            return false;
    }
    return true;
}

bool checkCol(int y, int x, map<char,int>& mp,const vector<vector<char>>& board)
{
    for(int i=0;i<9;i++)
    {
        if(board[i][x]=='.') continue;
        if(mp.find(board[i][x])==mp.end())
            mp[board[i][x]]++;
        else
            return false;
    }
    return true;
}

bool checkBox(int y, int x, map<char,int>& mp,const vector<vector<char>>& board)
{
    int yIdx = (y/3)*3;
    int xIdx = (x/3)*3;
    for(int i=yIdx;i<yIdx+3;i++)
    {
        for(int j=xIdx;j<xIdx+3;j++)
        {
            if(board[i][j]=='.') continue;
            if(mp.find(board[i][j])==mp.end())
                mp[board[i][j]]++;
            else
                return false;
        }
    }
    return true;
}
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        map<char,int> mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!checkRow(i,j,mp,board)) return false;
                mp.clear();
                if(!checkCol(i,j,mp,board)) return false;
                mp.clear();
                if(!checkBox(i,j,mp,board)) return false;
                mp.clear();
            }
        }
        return true;
    }
};