class Solution {
public:

    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        int n = nums.size();
        unordered_map<int, int> countMap;
        long long currentPairs = 0;
        int left = 0;

        for(int right=0;right<n;right++) {
            int num = nums[right];
            currentPairs += countMap[num];
            countMap[num]++;

           while(currentPairs >= k)
           {
                ans += (n - right);
                
                int lnum = nums[left];
                countMap[lnum]--;
                currentPairs -= countMap[lnum];
                left++;
           }
        }

        return ans;
    }
};
