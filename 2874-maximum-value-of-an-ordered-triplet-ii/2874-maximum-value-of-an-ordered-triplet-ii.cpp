class Solution {
public:
    long long triplet(int a, int b, int c){
        return (a-b)*(long long)c;
    }
    //1,2,6,7,12
    //6 * 12 or 11*7
    long long maximumTripletValue(vector<int>& nums) {
        long long answer = 0;
        for(int i=0;i<nums.size()-2;i++)
        {
            for(int j=i+1;j<nums.size()-1;j++)
            {
                if(nums[i]-nums[j] <=0)
                    break;
                for(int k=j+1;k<nums.size();k++)
                {
                    answer = max(answer,triplet(nums[i],nums[j],nums[k]));
                }
            }
        }
        return answer;
    }
};