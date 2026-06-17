class Solution {
public:
    string processStr(string s) {
        string result = "";

        for(const auto& ch : s)
        {
            if(ch>='a' && ch <='z')
                result += ch;
            else if(ch == '*')
            {
                if(result.size()!=0)
                    result.pop_back();
            }
            else if(ch=='#')
            {
                result += result;
            }
            else
            {
                if(result.size()!=0)
                    reverse(result.begin(),result.end());
            }
        }
        return result;
    }
};