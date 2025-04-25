class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans = 0;
        int prefix = 0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            prefix+= (nums[i]%modulo == k);
            int key = prefix%modulo; //개수 -> subarr이 몇개인지 조회용 
            if(mp.find(key)!=mp.end())
                ans += mp[key];
            mp[prefix % modulo]++;// prefix 개수 기록용
        }
        return ans;
    }
};