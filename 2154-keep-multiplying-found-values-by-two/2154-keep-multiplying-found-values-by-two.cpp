class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> s(nums.begin(),nums.end());
        int target = original;
        for(int i=0;i<s.size();i++)
        {
            if(s.find(target)==s.end())
                break;
            target *= 2;
        }
        return target;
    }
};