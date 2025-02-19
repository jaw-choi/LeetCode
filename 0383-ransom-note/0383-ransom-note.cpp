class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(auto s1 : ransomNote)
            mp1[s1]++;
        for(auto s2 : magazine)
            mp2[s2]++;    
        for(auto m : mp1)
        {
            if(mp2[m.first] < m.second)
                return false;
        }
        return true;
        // sort(magazine.begin(),magazine.end());
        // sort(ransomNote.begin(),ransomNote.end());
        // cout << magazine;
        // if(ransomNote.length()>magazine.length())
        //     return false;
        // for(int i=0;i<ransomNote.length();i++)
        // {
        //     if(ransomNote[i] != magazine[i])
        //         return false;
        // }
        // return true;
    }
};