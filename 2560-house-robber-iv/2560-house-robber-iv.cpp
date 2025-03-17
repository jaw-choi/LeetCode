class Solution {
public:
bool canRob(vector<int>& nums, int k, int maxCap) {
    int count = 0;
    int i = 0;
    while (i < nums.size()) {
        if (nums[i] <= maxCap) {
            count++;
            i += 2;  // 인접한 집을 건너뛰어야 함
        } else {
            i++;
        }
        if (count >= k) return true; // 최소 k개를 훔칠 수 있으면 true
    }
    return false;
}

int minCapability(vector<int>& nums, int k) {
    int left = *min_element(nums.begin(), nums.end());
    int right = *max_element(nums.begin(), nums.end());
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canRob(nums, k, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}
};