class Solution {
public:
    void sortColors(vector<int>& nums) {
        int idx = 0;
        int cnt0 =0;
        int cnt1 =0;
        int cnt2 =0;


        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                cnt0++;
            else if(nums[i]==1)
                cnt1++;
            else
                cnt2++;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(cnt0-->0)
                nums[i]=0;
            else if(cnt1-->0)
                nums[i]=1;
            else
                nums[i]=2;
        }
        
        
    }
};
