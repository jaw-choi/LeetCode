class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int ans = 0;
        sort(cost.begin(),cost.end(),greater<int>());
        int a=0,b=0,c=0;
        for(int i=0;i<n;i++)
        {
            if(i%3!=2)
                ans+=cost[i];
        }
        return ans;

    }
};
