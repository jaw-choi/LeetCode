class Solution {
public:
    void dfs(int curr,int& sum,const int& target,const string& num, unordered_map<int,int>& mp)
    {
        int val = num[curr]-'0';
        if(sum+val==target)
            return;
        if(sum+val>target)
        {
            //backtracking
            dfs(curr,sum-(num[curr-1]-'0'),target,num,mp);
            mp[num[curr-1]-'0']++;

        }
        else{
            dfs(curr+1,sum+val,target,num,mp);
            mp[num[curr]-'0']--;
        }
    }
    int countBalancedPermutations(string num) {
        int sum = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<num.length();i++){
            sum+=(num[i]-'0');
            mp[num[i]-'0']++;
        }

        if(sum%2!=0)
            return 0;
        if(num.length()%2==1)
            num+='0';
        dfs(0,sum,sum/2,num,mp);
        return sum;
    }
};