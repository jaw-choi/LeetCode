class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string str;
        map<string,char> mp1;
        map<char,string> mp;
        int cnt = 0;
        while(ss>>str)
        {
            if(mp.find(pattern[cnt])==mp.end())
                mp[pattern[cnt]] = str;
            else{
                if(mp[pattern[cnt]] != str)
                    return false;
            }

            if(mp1.find(str)==mp1.end())
                mp1[str] = pattern[cnt];
            else{
                if(mp1[str] != pattern[cnt])
                    return false;
            }
            cnt++;
        }
        cout << cnt;
        if(cnt != pattern.length())
            return false;
        return true;
    }
};