class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int next = 0;
        int remain = 0;
        while(numBottles!=0)
        {
            ans += numBottles;
            next = (numBottles + remain) / numExchange;
            remain = (numBottles + remain) % numExchange;
            numBottles = next;
            //cout << next<<" " << remain<<endl;

            //cout << ans <<endl;
        }
        return ans;
    }
};