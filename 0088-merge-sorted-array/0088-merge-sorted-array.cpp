class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = 0;
        for(int i=m;n!=0;n--)
        {
            nums1[i++] = nums2[idx++];
        }
        sort(nums1.begin(),nums1.end());
    }
};