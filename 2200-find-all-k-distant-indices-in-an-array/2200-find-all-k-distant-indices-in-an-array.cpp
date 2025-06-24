class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keyIndex;
        set<int> tmp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==key)
                keyIndex.push_back(i);
        }
        for(auto idx : keyIndex)
        {
            for(int i=idx-k;i<=idx+k;i++)
            {
                if(i>=0 && i <nums.size())
                {
                    tmp.insert(i);
                }
            }
        }
        for(auto s : tmp)
        {
            ans.push_back(s);
        }
        return ans;
    }
};