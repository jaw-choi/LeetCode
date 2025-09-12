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
        
        if(CountVowel(s)==0)
            return false;
        if(CountVowel(s)%2==1){
            return true;
            // if(s.length()==1)
            //     return true;
            // else
            //     return false;
        }
        if(CountVowel(s)%2==0)
            return true;
        return false;
    }
};