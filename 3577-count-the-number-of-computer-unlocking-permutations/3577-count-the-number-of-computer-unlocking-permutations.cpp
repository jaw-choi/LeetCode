class Solution {
public:
    int helper(int n)
    {
        long long ans = 1;
        int mod = 1e9 + 7;
        for(int i=n;i>0;i--)
        {
            ans = ((ans % mod) * i) % mod;
        }
        return ans % mod;
    }
    int countPermutations(vector<int>& complexity) {
        int root = complexity[0];
        int n = complexity.size();
        
        int ans = 1;
        map<int,int> mp;
        for(auto c : complexity){
            if(c < root)
                return 0;
            mp[c]++;
        }

        if(mp[root]>1)
            return 0;
        // for(auto m : mp)
        // {
        //     auto [com,num] = m;
        //     //ans *= helper(num);
        //     ans *= 1;
        // }

        return helper(n-1);
    }
};