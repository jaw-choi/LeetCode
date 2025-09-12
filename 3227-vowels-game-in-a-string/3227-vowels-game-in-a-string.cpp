class Solution {
public:
    int CountVowel(string& s)
    {
        int cnt = 0;
        for(auto& ch:s)
        {
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                cnt++;
        }
        return cnt;
    }
    bool doesAliceWin(string s) {
        int cntVowel = CountVowel(s);
        if(cntVowel==0)
            return false;
        return true;
    }
};