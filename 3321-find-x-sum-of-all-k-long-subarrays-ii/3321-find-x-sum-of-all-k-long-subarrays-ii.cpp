class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<long long> answer;
        int n = nums.size();
        long long tmp = 0;
        for (int i = 0; i < n - k + 1; i++) {
            unordered_map<long long, long long> mp;
            for (int q = i; q < i + k; q++)
                mp[nums[q]]++;

            priority_queue<pair<long long, long long>> pq;
            for (auto& m : mp) 
                pq.push({m.second, m.first});
            
            tmp = 0;
            for (int j = 0; j < x && !pq.empty(); j++) {
                //if(pq.size()==0) break;
                auto [cnt, num] = pq.top();
                //cout << cnt << " " << num << endl;
                pq.pop();
                tmp += (cnt * num);
            }
            answer.push_back(tmp);
        }
        return answer;
    }
};