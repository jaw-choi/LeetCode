class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        vector<int> v(nums.size(),0);
        v[0] = nums[0];
        for(int i=1;i<nums.size();i++)
            v[i]=v[i-1]+nums[i];
        int l=0;

        while(l<v.size())
        {
            //-1,-2,-1
            for(int r =l;r<v.size();r++)
            {
                //if(l!=0)
                   // cout << l << " " << r << " " <<v[r]-v[l-1]<<endl;
                if(l==0){
                    if(v[r]==k)
                        cnt++;
                }
                else{
                    if(v[r]-v[l-1] == k)
                        cnt++;
                }
            }
            l++;
        }
        return cnt;
    }
};
//1,2,3