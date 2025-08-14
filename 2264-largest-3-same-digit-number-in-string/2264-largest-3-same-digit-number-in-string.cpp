class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        string tmp="";
        int cnt=0;
        for(int i=0;i<num.length()-2;i++)
        {
            if(num[i]==num[i+1] && num[i+1] == num[i+2]){
                if(tmp=="" || num[i]>tmp[0]){
                    tmp=num[i];
                    tmp+=num[i+1];
                    tmp+=num[i+2];
                }
                if(ans<tmp)
                    ans = tmp;
            }
        }
        return ans;
    }
};