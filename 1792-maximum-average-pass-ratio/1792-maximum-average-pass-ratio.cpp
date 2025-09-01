class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        // max-heap based on gain
        auto cmp = [&](const pair<int,int>& a, const pair<int,int>& b) {
            return gain(a.first, a.second) < gain(b.first, b.second);
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

        for (auto& c : classes) {
            pq.push({c[0], c[1]}); // (pass, total)
        }

        while (extraStudents--) {
            auto [pass, total] = pq.top();
            pq.pop();
            pass++;
            total++;
            pq.push({pass, total});
        }

        double ratio = 0;
        while (!pq.empty()) {
            auto [pass, total] = pq.top();
            pq.pop();
            ratio += (double)pass / total;
        }

        return ratio / classes.size();
    }
};
