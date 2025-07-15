class Solution {
public:
    bool isValid(string word) {
        if(word.length()<3)
            return false;
        bool num = false;
        bool vow = false;
        bool con = false;
        for(auto ch : word)
        {
            if((ch-'0') >=0 && (ch-'0') <= 9)
                num = true;
            else if(((ch-'a')>=0 && (ch-'a')<=25) || (ch-'A')>=0 && (ch-'A')<=25)
            {
                if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'
                    || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
                    vow = true;
                else
                    con = true;
            }
            else
                return false;
        }
        if(!vow || !con)
            return false;
        return true;
    }
};