class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long left = 1;
        long long right = *max_element(candies.begin(),candies.end());
        int ans = 0;
        while(left<=right)
        {
            long long mid = (left+right) / 2;
            long long childNum = 0;
            for(auto c : candies)
                childNum += c/mid;
            
            if(childNum >= k){
                ans = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return ans;
    }
};