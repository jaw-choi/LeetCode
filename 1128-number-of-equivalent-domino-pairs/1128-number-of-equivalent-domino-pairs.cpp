class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans  = 0;
        for(auto& d : dominoes)
        {
            int tmp = 0;
            if(d[0]>d[1]){
                tmp = d[0];
                d[0] = d[1];
                d[1] = tmp;
            }
        }
        sort(dominoes.begin(),dominoes.end());

        vector<int> curr = dominoes[0];
        int cnt = 1;
        for(int i=1;i<dominoes.size();i++)
        {
            if(curr == dominoes[i])
                cnt++;
            else{
                ans += (cnt*(cnt-1)/2);
                curr = dominoes[i];
                cnt = 1;
            }
        }   
        //if(cnt!=1)
            ans += (cnt*(cnt-1)/2);
        return ans;
    }
};