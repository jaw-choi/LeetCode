class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int ans = 0;
        for (auto n : nums)
            right += n;

        for (int i = 0; i < nums.size()-1; i++) {
            right -= nums[i];
            left += nums[i];
            //cout << right << " " << left << endl;
            if ((right - left) % 2 == 0)
                ans++;
        }
        return ans;
    }
};