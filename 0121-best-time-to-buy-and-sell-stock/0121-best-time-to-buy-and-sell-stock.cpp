class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left=0;
        int ans=0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[left]>prices[i])
                left=i;
            if(ans < prices[i]-prices[left])
            {
                ans = prices[i]-prices[left];
            }

        }
        return ans;
    }
};