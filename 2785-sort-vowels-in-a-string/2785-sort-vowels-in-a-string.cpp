class Solution {
public:
    bool isVowel(char c)
    {
        if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            return true;
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
            return true;
        return false;
    }
    string sortVowels(string s) {
        
        priority_queue<char,vector<char>,greater<char>> pq;
        for(auto ch : s)
        {
            if(isVowel(ch)){
                pq.push(ch);
            }
        }
        for(auto& ch : s)
        {
            if(isVowel(ch))
            {
                auto alp = pq.top();
                pq.pop();
                ch = alp;
            }
        }
        return s;
    }
};