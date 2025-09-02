class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b)
    {
        if(a[0] == b[0]){
            return a[1]>b[1];
        }
        return a[0] < b[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        sort(points.begin(),points.end(),cmp);
        for(int i=0;i<n;i++)
        {
            auto& pA = points[i];
            for(int j=0;j<n;j++)
            {
                vector<int> pB = points[j];
                if(i==j)continue;
                if(!(pA[0]<=pB[0] && pA[1]>=pB[1])) continue;
                if(n==2){
                    ans++;
                    continue;
                }

                bool flag = false;
                for(int k=0;k<n;k++){
                    if(k==i || k==j) continue;
                    auto& pointTmp = points[k];
                    bool isXContained =
                        pointTmp[0] >= pA[0] && pointTmp[0] <= pB[0];
                    bool isYContained =
                        pointTmp[1] <= pA[1] && pointTmp[1] >= pB[1];
                    if(isXContained && isYContained){
                        flag = true;
                        break;
                    }
                }
                if(!flag) ans++;
            }
        }
        return ans;
    }
};