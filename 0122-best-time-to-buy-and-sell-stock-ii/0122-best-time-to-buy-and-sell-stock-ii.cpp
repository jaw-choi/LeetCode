class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int idx = 0;
        int left = 0;
        int ans = 0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[left] >= prices[i])            
                left = i;            
            else
            {
                if(i+1 < prices.size())
                {
                    if(prices[i]>=prices[i+1]){
                        ans += prices[i]-prices[left];
                        left = i+1;
                    }
                }
                else
                {
                    if(prices[i]-prices[left]>0)
                        ans+=prices[i]-prices[left];
                    
                }
            }
        }
        return ans;
    }

};