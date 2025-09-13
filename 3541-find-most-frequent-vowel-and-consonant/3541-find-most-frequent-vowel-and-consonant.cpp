class Solution {
public:
    int maxFreqSum(string s) {
        int maxV=0;
        int maxC=0;
        unordered_map<char,int> mp;
        for(auto& ch : s)
        {
            mp[ch]++;
        }
        for(auto m : mp)
        {
            char ch = m.first;
            int cnt = m.second;
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ){
                if(cnt > maxV)
                    maxV = cnt;
            }
            else{
                if(cnt > maxC)
                    maxC = cnt;
            }
        }
        return maxV + maxC;
    }
};