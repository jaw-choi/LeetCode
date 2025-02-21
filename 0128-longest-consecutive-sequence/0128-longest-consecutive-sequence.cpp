class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        int ans = 0;
        int tmp = 0;
        int prev = 0;
        for(auto n : nums)
            s.insert(n);
        for(auto num : s)
        {
            if(ans==0){
                prev = num;
                ans=1;
                tmp = 1;
            }
            else
            {
                if(num == prev+1)
                {
                    prev = num;
                    tmp++;
                    ans = max(ans,tmp);
                }
                else
                {
                    tmp=1;
                    prev = num;
                }
            }
        }
        return ans;
    }
};