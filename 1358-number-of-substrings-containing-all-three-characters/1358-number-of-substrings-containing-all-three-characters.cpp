class Solution {
public:
    int numberOfSubstrings(string s) {
        int left=0;
        int cnt = 0;
        unordered_map<char,int> mp;
        mp['a']=0;
        mp['b']=0;
        mp['c']=0;
        for(int right = 0;right<s.length();right++)
        {
            mp[s[right]]++;
            while(mp['a']>0 && mp['b']>0 && mp['c']>0)
            {
                cnt += s.length()-right;
                mp[s[left]]--;
                left++;
            }
        }
        return cnt;
    }
};