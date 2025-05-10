class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0, sum2=0;
        // int i = 0;
        // while (i < nums1.size() || i < nums2.size()) {
        //     if (i >= nums1.size()) {
        //         sum2 += nums2[i];
        //     } else if (i >= nums2.size()) {
        //         sum1 += nums1[i];
        //     } else {

        //         if (nums1[i] - nums2[i] < nums2[i] - nums1[i]) {
        //             sum2 += nums2[i] - nums1[i];
        //         } else {
        //             sum1 += nums1[i] - nums2[i];
        //         }
        //     }
        //     i++;
        // }
        // sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        // sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        for(auto s :nums1)
            sum1+=s;
        for(auto d : nums2)
            sum2+=d;
        cout << sum1 <<" "<<sum2;
        long long numZero1 = 0, numZero2 = 0;
        for (auto n1 : nums1) {
            if (n1 == 0)
                numZero1++;
        }
        for (auto n2 : nums2) {
            if (n2 == 0)
                numZero2++;
        }
        if (numZero1 != 0 && numZero2 != 0) {
            return max(sum1 + numZero1, sum2 + numZero2);
        } else {
            if (numZero1 == 0 && numZero2 == 0) {
                if (sum1 != sum2)
                    return -1;
                else
                    return sum1;
            } else if (numZero1 == 0) {
                if (sum1 < sum2)
                    return -1;
                else if (sum1 < sum2 + numZero2)
                    return -1;
                else {
                    return sum1;
                }
            } else if (numZero2 == 0) {
                if (sum2 < sum1)
                    return -1;
                else if (sum2 < sum1 + numZero1)
                    return -1;
                else {
                    return sum2;
                }
            }
        }
        return -1;
    }
};