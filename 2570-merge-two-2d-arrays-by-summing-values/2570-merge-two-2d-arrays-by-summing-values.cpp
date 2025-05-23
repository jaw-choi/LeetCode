class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int currId = 1;
        int i=0,j=0;
        vector<vector<int>> ans;
        while(i<nums1.size() || j<nums2.size())
        {
            int sum = 0;
            if(i<nums1.size()&&nums1[i][0]==currId){
                sum+=nums1[i][1];
                i++;
            }
            if(j<nums2.size()&&nums2[j][0]==currId){
                sum+=nums2[j][1];
                j++;
            }
            if(sum!=0)
                ans.push_back({currId,sum});
            currId++;
        }
        return ans;
    }
};