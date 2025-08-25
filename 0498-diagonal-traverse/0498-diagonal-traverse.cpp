class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int cnt = 0;
        int n = mat.size();
        int m = mat[0].size();
        int all = n * m;
        int i = 0, j = 0;
        bool dir = true;
        while (cnt < all) {
            ans.push_back(mat[i][j]);
            // move
            if (dir) {
                if (i - 1 < 0 || j + 1 >= m) {
                    if (j + 1 < m) {
                        j++;
                    } else {
                        i++;
                    }
                    dir = !dir;
                }
                else{
                    i--;j++;
                }
            } else {
                if(i+1 >=n || j - 1 < 0){
                    if(i+1 < n){
                        i++;
                    }
                    else{
                        j++;
                    }
                    dir=!dir;
                }
                else{
                    i++;j--;
                }
            }
            cnt++;
        }
        return ans;
    }
};