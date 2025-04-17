class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int cnt = 0;
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
        
        for(auto m : mp)
        {
            for(int i=0;i<m.second.size();i++)
            {
                for(int j=i+1;j<m.second.size();j++)
                {
                    if((m.second[i]*m.second[j])%k==0){
                        //cout << m.second[i]<<m.second[j]<<endl;
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};