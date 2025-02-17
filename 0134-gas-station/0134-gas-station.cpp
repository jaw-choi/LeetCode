class Solution {
public:
    bool circular(int idx,int curr,int cnt, vector<int>& gas, vector<int>& cost)
    {
        if(cnt == gas.size())
            return true;
        if(curr+gas[idx] - cost[idx] < 0)
            return false;
        else
        {
            if(idx+1>=gas.size())
                return circular(0,curr+gas[idx] - cost[idx],cnt+1,gas,cost);
            else
                return circular(idx+1,curr+gas[idx] - cost[idx],cnt+1,gas,cost);
        }
        return false;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size()==1 && gas[0] == cost[0])
            return 0;
        for(int i=0;i<gas.size();i++)
        {
            if(gas[i] <= cost[i])
                continue;
            if(circular(i,0,0,gas,cost))
                return i;
        }
        return -1;
    }
};