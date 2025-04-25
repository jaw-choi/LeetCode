class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=(nums[i]%k + k) %k;
            int remainder = sum%k;
            if(mp.find(remainder)!=mp.end())
                ans += mp[remainder];//ans+=0,ans+=1,ans+=2,ans+=3,ans++
            mp[remainder]++;//mp[4]++,mp[4]++,mp[4]++,mp[2]++,mp[4]++,mp[0]++
        }
            //k=5
            //ans+=0, ans+=1,ans+=2,   ans+=0, ans+=3, ans++
            //4,      5      ,0        ,-2,    -3,     1
            //mp[4]++,mp[4]++,mp[4]++, mp[2]++,mp[4]++,mp[0]++

            //-1,1,10 ,k = 2;
            /*
            //ans+=0, ans+=0,ans+=1
            //-1,      1      ,10     
            //mp[-1]++,mp[1]++,mp[0]++
            //k=3,  2,0 
            */

        return ans;
    }
};