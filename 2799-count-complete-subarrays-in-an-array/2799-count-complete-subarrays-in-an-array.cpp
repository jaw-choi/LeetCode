class Solution {
public:
    bool helper(int left, int right, int size_, const vector<int>& nums)
    {
        unordered_set<int> s(nums.begin()+left,nums.begin()+right+1);
        if(s.size()<size_)
            return false;
        return true;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> s(nums.begin(),nums.end());
        int minimumSize = s.size();
        unordered_set<int> window;
        int i = 0;
        while(window.size()<minimumSize && i <nums.size())
            window.insert(nums[i++]);
        int left = 0;
        int init = i-1;
        int right = init;
        //3,2,2,1,1,4,1,1
        while(left+minimumSize-1<nums.size())
        {
            //cout << ans << ","<<left<<","<<right<<endl;
            if(helper(left,right,minimumSize,nums))
                ans += nums.size() - right;
            else{
                while(right < nums.size() && !helper(left,right,minimumSize,nums)){
                    right++;
                }
                 if(right>=nums.size())
                    return ans;
                else
                    ans+= nums.size() - right;
            }
            left++;
            right = left + minimumSize - 1;
            if(right<init)
                right=init;
        }
        return ans;
    }
};