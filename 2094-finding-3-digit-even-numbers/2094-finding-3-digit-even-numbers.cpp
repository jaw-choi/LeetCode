class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        set<int> s;
        int num = 0;
        for(int i=0;i<digits.size();i++)
        {
            if(digits[i]==0)
                continue;
            for(int j=0;j<digits.size();j++)
            {
                num = digits[i]*100;
                if(i==j) continue;
                num += digits[j]*10;
                for(int k=0;k<digits.size();k++)
                {
                    if(i==k || j==k) continue;
                    if(digits[k]!=0 && digits[k]%2!=0)
                        continue;
                    int tmp = num;
                    tmp+=digits[k];
                    if(s.find(tmp)!=s.end())
                        continue;
                    s.insert(tmp);
                    ans.push_back(tmp);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};