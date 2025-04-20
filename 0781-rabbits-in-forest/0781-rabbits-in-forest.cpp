class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        unordered_map<int,int> mp;
        sort(answers.begin(),answers.end());
        //11 1,222 222 2
        //2+2, 3+3 +3 = 4 + 6 + 3= 13 
        for(auto a : answers)
        {
            mp[a]++;
        }
        for(auto m : mp)
        {
            if(m.first==0){
                ans+=m.second;
                continue;
            }
            if(m.first+1 < m.second)
                ans += (m.first+1)*((m.second-1)/(m.first+1) + 1); //2*2 = 4, 3*
            else            
                ans+=(m.first+1);

        }
        return ans;
    }
};