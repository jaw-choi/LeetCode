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
        int answer = 0;
        int prevMaxY = 0;
        sort(points.begin(),points.end(),cmp);
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                if(i==j-2)
                    prevMaxY = points[j-1][1];
                if(i<=j-2)
                {
                    if(prevMaxY < points[j][1] && points[i][1] >= points[j][1])
                        answer++;
                    prevMaxY = max(prevMaxY,points[j][1]);

                }
                else{
                    if(points[i][1] < points[j][1])
                        break;
                    else
                        answer++;
                }

            }
        }
        return answer;
    }
};