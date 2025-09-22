class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq = 0;
        int cnt = 0;
        map<int,int> mp;
        for(auto& n : nums)
        {
            mp[n]++;
        }
        for(auto& m : mp)
        {
            if(m.second > maxFreq){
                maxFreq = m.second;
                cnt = m.second;
            }
            else if(maxFreq == m.second)
                cnt += m.second;
        }
        return cnt;
    }
};