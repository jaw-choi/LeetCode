class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left=0;
        int right=0;
        int ans=0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[left]>prices[i]){
                left=i;
                right=i;
            }
            if(prices[right]<prices[i]){
                right=i;
            }
            ans = max(ans,prices[right]-prices[left]);
        }
        return ans;
    }
};