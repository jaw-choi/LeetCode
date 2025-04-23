class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        for(int i=1;i<=n;i++)
        {
            int tmp = i;
            int cnt = 0;
            while(tmp!=0)
            {
                cnt += tmp%10;
                tmp/=10;
            }
            mp[cnt]++;
        }
        int ans = 0;
        int size_ = 0;
        for(auto m : mp)
            size_ = max(size_,m.second);
        for(auto m : mp)
        {
            if(m.second == size_)
                ans++;
        }
        return ans;
    }
};