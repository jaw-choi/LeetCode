class Solution {
public:
    const int MOD = 1e9 + 7;
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;

        long long evenWays = helper(5,even);
        long long oddWays = helper(4,odd);

        return ((evenWays%MOD)*(oddWays%MOD))%MOD;
    }
    long long helper(long long base, long long power)
    {
        long long ans = 1;

        while(power>0){
            if(power%2==1)
                ans = (ans*base)%MOD;
            base *= base;
            base %= MOD;
            power /=2; 
        }
        return ans;
    }
};