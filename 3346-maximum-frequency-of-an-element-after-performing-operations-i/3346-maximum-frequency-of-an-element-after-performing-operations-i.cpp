class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int mxNum = *max_element(nums.begin(),nums.end());
        int n = mxNum + k + 2;
        vector<int> count(n,0);
        for(auto v: nums)
            count[v]++;
        for(int i=1;i<n;i++)
        {
            count[i] += count[i-1];
        }
        int res = 0'
        for (int i = 0; i < n; i++) {
            int left = max(0, i - k);
            int right = min(n - 1, i + k);
            int total = count[right] - (left ? count[left - 1] : 0);
            int freq = count[i] - (i ? count[i - 1] : 0);
            res = max(res, freq + min(numOperations, total - freq));
        }
        return res;
    }
};