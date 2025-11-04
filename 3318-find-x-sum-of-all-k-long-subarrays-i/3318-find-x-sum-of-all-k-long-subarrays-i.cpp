class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> answer;
        int n = nums.size();
        int tmp = 0;
        for (int i = 0; i < n - k + 1; i++) {
            unordered_map<int, int> mp;
            for (int q = i; q < i + k; q++)
                mp[nums[q]]++;

            priority_queue<pair<int, int>> pq;
            for (auto& m : mp) 
                pq.push({m.second, m.first});
            
            tmp = 0;
            for (int j = 0; j < x; j++) {
                if(pq.size()==0) break;
                auto [cnt, num] = pq.top();
                pq.pop();
                tmp += (cnt * num);
            }
            answer.push_back(tmp);
        }
        return answer;
    }
};