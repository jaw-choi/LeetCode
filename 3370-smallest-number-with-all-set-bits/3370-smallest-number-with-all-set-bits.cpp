class Solution {
public:
    int smallestNumber(int n) {
        int ans = 1;
        while(1)
        {
            if(ans >= n){
                return ans;
            }
            else{
                ans = ans << 1;
                ans++;
            }
        }
        return 0;
    }
};