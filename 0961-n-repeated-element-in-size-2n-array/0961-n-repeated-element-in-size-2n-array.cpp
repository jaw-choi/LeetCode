class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> s;
        for(auto& n : nums)
        {
            if(s.count(n))
                return n;
            s.insert(n);       
        }

        return 0;
    }
};