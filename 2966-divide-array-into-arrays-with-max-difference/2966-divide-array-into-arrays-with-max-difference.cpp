class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int num = nums.size()/3;
        for(int i=0;i<nums.size();i+=3)
        {
            int tmp = nums[i];
            vector<int> tmpv;
            for(int j=0;j<3;j++)
            {
                if(abs(nums[i+j] - tmp) > k)
                    return vector<vector<int>>();
                tmpv.push_back(nums[i+j]);
            }
            ans.push_back(tmpv);

        }
        return ans;
    }
};