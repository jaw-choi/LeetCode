class Solution {
public:
    int longestSubsequence(string s, int k) {
        int curr = 1;
        int num = 0;
        int cnt = 0;
        cout << s.length()<<endl;
        for(auto it=s.rbegin();it<s.rend();++it)
        {
            if(*it=='1' && (num+curr <= k)){
                num += curr;
                cnt++;
                //cout <<*it;
            }
            else if(*it=='0'){
                cnt++;
                //cout <<*it;
            }
            if(curr <= k)
                curr*=2;
        }
        return cnt;
    }
};