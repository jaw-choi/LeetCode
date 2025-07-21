class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int cnt = 0;
        char prev = s[0];
        for(auto& ch : s)
        {
            if(prev == ch)
                cnt++;
            else
                cnt = 1;
            if(cnt<3)
                ans += ch;
            prev = ch;
            //cout << cnt << ch <<endl;
        }
        return ans;
    }
};