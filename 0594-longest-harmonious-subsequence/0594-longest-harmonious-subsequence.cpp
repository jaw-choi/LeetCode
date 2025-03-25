class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> mp;
        for(auto n : nums)
            mp[n]++;
        int left = *min_element(nums.begin(),nums.end());
        int right = *max_element(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end() &&
               mp.find(nums[i]+1)!=mp.end())
               {
                int cnt = mp[nums[i]]+mp[nums[i]+1];
                if(ans < cnt)
                    ans = cnt;
                //cout << nums[i]<<","<<ans << endl;
               }
        }
        return ans;
    }
};//1,2,2,2,3,3,5,7