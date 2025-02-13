class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = nums1.size()-1;
        int left = m-1;
        int right = n-1;
        for(int i=idx;i>=0;i--)
        {
            if(left<0){
                nums1[i]=nums2[right--];
                continue;
            }
            if(right<0){
                nums1[i]=nums1[left--];
                continue;
            }
            if(nums1[left] >= nums2[right])
                nums1[i]=nums1[left--];
            else
                nums1[i]=nums2[right--];
        }
        
    }
};