class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        int curr = 0;
        for(int i=0;i<dimensions.size();i++)
        {
            int l = dimensions[i][0];
            int w = dimensions[i][1];
            int dia = l*l + w*w;
            if(curr < dia){
                curr = dia;
                ans = l*w;
            }
        }
        return ans;
    }
};