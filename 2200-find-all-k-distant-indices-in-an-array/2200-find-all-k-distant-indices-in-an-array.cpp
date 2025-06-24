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
        int curr = keyIndex[0];
        for(int i=0,j=0;i<nums.size();i++)
        {
            if(abs(i-curr)<=k)
                ans.push_back(i);
            else{
                if(i<curr)
                    continue;
                else{
                ++j;
                if(j>=keyIndex.size())
                    break;
                curr=keyIndex[j];
                if(abs(i-curr)<=k)
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};