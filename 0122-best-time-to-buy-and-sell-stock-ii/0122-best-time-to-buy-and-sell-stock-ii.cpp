class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int idx = 0;
        int left = 0;
        int ans = 0;
        for(int i=1;i<prices.size();i++)
        {
            int price = prices[i] - prices[i-1];
            if(price>0)
                ans+=price;
        }
        return ans;
    }

};