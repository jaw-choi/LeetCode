class Solution {
public:
    long long helper(long long n)
    {
        return (n*(n+1) / 2) - n;
    }
    long long getDescentPeriods(vector<int>& prices) {
        int left = 0, right = 1;
        int n = prices.size();
        long long ans = n;
        int cnt = 1;
        if(n==1)
            return 1;
        while(right < n)
        {
            if(prices[left] - cnt == prices[right])
            {
                right++;
                cnt++;
            }
            else
            {
                if(cnt!=1)
                {
                    ans += helper(right - left);
                    //cout << left << " " << right <<endl;
                    left = right;
                    right = left + 1;
                    cnt = 1;
                }
                else{
                    left++;
                    right = left+1;
                }
            }
        }
                if(cnt!=1)
                {
                    ans += helper(right - left);
                    //cout << left << " " << right <<endl;
                }
        return ans;
    }
};