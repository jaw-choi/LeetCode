class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans1;
        vector<string> ans2;
        int n = words.size();
        bool flag1 = false;
        bool flag2 = false;
        for(int i=0;i<n;i++)
        {
            if(flag1==false){
                if(groups[i]==0){
                    ans1.push_back(words[i]);
                    flag1=true;
                }
            }
            else{
                if(groups[i]==1){
                    ans1.push_back(words[i]);
                    flag1=false;
                }
            }

            if(flag2==false){
                if(groups[i]==1){
                    ans2.push_back(words[i]);
                    flag2=true;
                }
            }
            else{
                if(groups[i]==0){
                    ans2.push_back(words[i]);
                    flag2=false;
                }
            }
        }
        return ans1.size()>ans2.size() ? ans1 : ans2;
    }
};