#include <bits/stdc++.h>
using namespace std;

class Solution {
    static const int MOD = 1e9+7;

    long long ipow(long long a, int x) {
        long long r = 1;
        while (x) {
            if (x & 1) r *= a;
            a *= a;
            x >>= 1;
        }
        return r;
    }

public:
    int numberOfWays(int n, int x) {
        vector<int> powers;
        for (long long i = 1;; ++i) {
            long long p = ipow(i, x);
            if (p > n) break;
            powers.push_back((int)p);
        }

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int p : powers) {
            for (int s = n; s >= p; --s) {
                dp[s] += dp[s - p];
                if (dp[s] >= MOD) dp[s] -= MOD;
            }
        }
        return dp[n];
    }
};
