class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        //1 6, 2 8,7 12, 10 16
        sort(points.begin(),points.end(),cmp);
        int ans = 0;
        int right = points[0][1];
        for(auto p : points)
        {
            if(right >= p[0])
                continue;
            else
            {
                right = p[1];
                ans++;
            }
        }
        return ans+1;
    }
};