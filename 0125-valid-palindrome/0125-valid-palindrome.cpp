class Solution {
public:
    bool isPal(string s)
    {
        if(s.length()==0)
            return true;
        int left = 0;
        int right = s.length()-1;
        while(left<=right)
        {
            if(s[left]!=s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string tmp="";
        for(auto str : s)
        {
            if(str>='A' && str<='Z')
            {
                tmp+= str+32;
            }
            else if(str>='a' && str<='z')
            {
                tmp+=str;
            }
            else if(str>='0' && str<='9')
            {
                tmp += str;
            }
        }
        return isPal(tmp);
    }
};