class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = accumulate(gas.begin(),gas.end(),0);
        int costSum = accumulate(cost.begin(),cost.end(),0);
        int ans = 0;
        if(gasSum < costSum)
            return -1;
        int sum=0;
        for(int i=0;i<gas.size();i++)
        {
            sum += gas[i] - cost[i];
            if(sum < 0)
            {
                sum = 0;
                ans = i+1;
            }
        }
        return ans;
    }
};