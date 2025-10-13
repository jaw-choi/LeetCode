class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 1;
        int n = prices.size();
        int ans = 0;
        while(right<n)
        {
            ans = max(ans,prices[right]-prices[left]);
            if(prices[left] <= prices[right])
                right++;
            else{
                left++;
                right = left+1;
            }
        }
        return ans;
    }
};