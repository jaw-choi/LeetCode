class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        //1,2,2,3,3,3,4,5,7
        //1,2,3,4,2,3,3,5,7
        //4,2,3,3,5,7
        //3,5,7
        //5,9,3,2,1,3

        int answer = 0;
        for(int i=0;i<nums.size();i+=3)
        {
            set<int> s(nums.begin()+i,nums.end());
            if(s.size()==nums.size()-i)
                return answer;
            answer++;
        }
        return answer;
/*
bitset<51> bit(1);
            for(int j=i;j<nums.size();j++)
            {
                if((bit&bit<<nums[j])!=0){
                    cout <<endl;
                    break;
                }
                bit |= bit<<nums[j];
                cout << bit.to_string() << " "<< nums[j]<< endl;
                if(j==nums.size()-1)
                    return answer;
            }
            answer++;
*/
    }
};