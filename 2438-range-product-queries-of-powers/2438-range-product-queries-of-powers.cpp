class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod = 1e9+7;
        int curr = 1;
        vector<int> power;
        vector<int> answer;
        while(n){
            if(n&1)
                power.push_back(curr);
            curr*=2;
            n = n>>1;
        }
        for(auto& q : queries)
        {
            int start = q[0];
            int end = q[1];
            long long num = 1;
            for(int i=start;i<=end;i++)
            {
                num = (long long)((num%mod) * power[i])%mod;
            }
            answer.push_back(num%mod);
        }
        return answer;
    }
};
//1111