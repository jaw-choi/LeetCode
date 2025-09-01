class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto profit = [](int pass, int total){
            return ((double)(pass+1)/(total+1)) - ((double)pass/total);
        };
        double answer = 0;
        double n = (double)classes.size();
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<classes.size();i++)
        {
            pq.push({profit(classes[i][0],classes[i][1]),i});
        }
        while(extraStudents--)
        {
            auto score = pq.top();
            pq.pop();
            int idx = score.second;
            classes[idx][0]++;
            classes[idx][1]++;
            pq.push({profit(classes[idx][0],classes[idx][1]),idx});
        }
        for(auto& c : classes)
        {
            answer += (double)c[0]/c[1];
        }
        return answer/n;
    }
};