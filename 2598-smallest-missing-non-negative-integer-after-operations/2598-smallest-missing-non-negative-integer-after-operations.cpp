class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int,int> mp;
        for(auto& n : nums)
        {
            int mod = (n%value + value) % value;
            mp[mod]++;
        }
        int mex = 0;
        while(mp[mex % value] > 0)
        {
            mp[mex%value]--;
            mex++;
        }
        return mex;
    }
};