class Solution {
public:
    string operation(const string& s)
    {
        string tmp;
        for(int i=0;i<s.size()-1;i++)
        {
            tmp += to_string((((s[i]-'0') + (s[i+1]-'0'))%10));
        }
        return tmp;
    }
    bool hasSameDigits(string s) {
        
        while(s.size()!=2)
        {
            for(int i=0;i<s.size()-1;i++)
            {
                s[i] = (((s[i]-'0') + (s[i+1]-'0'))%10) + '0';
            }
            s.pop_back();
            //s = operation(s);
        }
        return s[0]==s[1];
    }
};