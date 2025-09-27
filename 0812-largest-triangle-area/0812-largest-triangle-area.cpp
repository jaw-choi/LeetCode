class Solution {
public:
    double getLTA(vector<int>& a,vector<int>& b,vector<int>& c)
    {
        int minX = min(a[0],min(b[0],c[0]));
        int minY = min(a[1],min(b[1],c[1]));
        int maxX = max(a[0],max(b[0],c[0]));
        int maxY = max(a[1],max(b[1],c[1]));
        cout << maxY << " "<< maxX << " "<< minY << " "<< minX << " "<<endl;
        return (maxY - minY) * (maxX - minX) / 2.0;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double answer = 0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    cout << i<<j<<k<<endl;
                    answer = max(answer,getLTA(points[i],points[j],points[k]));
                }
            }
        }
        return answer;
    }
};