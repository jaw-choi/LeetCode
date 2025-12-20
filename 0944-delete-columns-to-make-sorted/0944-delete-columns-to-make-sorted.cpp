class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;
        char prev = strs[0][0];
        for(int i=0;i<m;i++)
        {
            prev = strs[0][i];
            for(int j=0;j<n;j++)
            {
                if(strs[j][i] < prev){
                    ans++;
                    break;
                }
                prev = strs[j][i];
            }
        }
        return ans;
    }
};