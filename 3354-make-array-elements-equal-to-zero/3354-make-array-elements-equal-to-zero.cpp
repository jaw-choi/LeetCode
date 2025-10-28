class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum = 0;
        int curr=0;
        int answer=0;
        for(auto& n : nums)
        {
            sum += n;
        }
        for(int i=0;i<nums.size();i++)
        {
            curr += nums[i];
            if(nums[i]==0)
            {
                if(sum-curr==curr)
                    answer+=2;
                else if(sum-curr==curr+1 || sum-curr==curr-1)
                    answer++;
            }
        }
        return answer;
    }
};