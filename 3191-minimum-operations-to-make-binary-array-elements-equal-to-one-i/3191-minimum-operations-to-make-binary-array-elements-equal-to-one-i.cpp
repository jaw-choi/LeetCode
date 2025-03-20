class Solution {
public:
    void helper(int idx, vector<int>& nums)
    {
        for(int i=idx;i<idx+3;i++)
        {
            if(nums[i]==1)
                nums[i]=0;
            else
                nums[i]=1;
        }
    }
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        int ans = 0;
        int dummy = 0;
        bool flag = false;
        // for(auto n : nums)
        // {
        //     if(n==1)
        //         flag = false;
        //     if(n==0)
        //     {
        //         if(flag==true)
        //             continue;
        //         else{
        //             flag=true;
        //             dummy++;
        //         }
        //     }
        // }
        // for(auto n : nums)
        //     if(n==0)
        //         cnt++;
        // if(dummy%2!=0)
        //     if(cnt%3!=0)
        //         return -1;
        for(int i=0;i<nums.size()-2;i++)
        {
            if(nums[i]==0){
                helper(i,nums);
                ans++;
            }
        }
        for(auto n : nums)
            if(n==0)
                return -1;
        return ans;
    }
};
//[1,0,1,0,0,1,0,1]
//[1,1,0,1,0,1,0,1]
//[1,1,1,0,1,1,0,1]
//[1,1,1,1,0,0,0,1]
//[1,1,1,1,1,1,1,1]