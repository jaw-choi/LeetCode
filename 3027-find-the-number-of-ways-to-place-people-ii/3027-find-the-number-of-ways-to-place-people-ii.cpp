class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        if(a[0] == b[0]){
            return a[1]<b[1];
        }
        return a[0] > b[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        sort(points.begin(),points.end(),cmp);

        for(int i=0;i<n-1;i++)
        {
            int y = INT_MAX,yi=points[i][1];
            //auto& pA = points[i];
            for(int j=i+1;j<n;j++)
            {
                int yj = points[j][1];
                if(yj>=yi && y>yj){
                    ans++;
                    y=yj;
                    if(yi==yj) break;
                }
            }
        }
        return ans;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();