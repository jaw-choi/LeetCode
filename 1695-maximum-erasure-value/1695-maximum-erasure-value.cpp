class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;
        queue<int> q;
        int ans = 0;
        int cnt = 0;
        int left=0, right=0;
        int curr=0;
        while(right<nums.size())
        {
            curr = nums[right];

            if(mp.find(curr)!=mp.end()){
                while(mp.find(curr)!=mp.end())
                {
                    mp[nums[left]]--;
                    cnt-=nums[left];
                    if(mp[nums[left]]==0)
                        mp.erase(nums[left]);
                    left++;
                }
            }
            mp[curr]++;
            cnt+=curr;
            right++;
            ans = max(ans,cnt);
        }
        return ans;
    }
};