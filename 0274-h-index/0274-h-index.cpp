class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(),citations.rend());
        int ans = 0;
        //6,5,3,0,1
        for(int i=0;i<citations.size();i++)
        {
            if(citations[i] >= ans + 1)
            {
                ans++;
            }
        }
        return ans;
    }
};