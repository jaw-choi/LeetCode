#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<long long, int> countByValue; // cnt[v]
        map<long long, int> diff;                   // difference map for interval cover

        for (long long x : nums) {
            ++countByValue[x];
            diff[x];                 // ensure we evaluate at existing value positions
            ++diff[x - k];           // start of [x-k, x+k]
            --diff[x + k + 1];       // end + 1
        }

        int ans = 0;
        long long cover = 0;          // s(v): how many intervals cover current v
        for (auto& kv : diff) {
            long long v = kv.first;
            cover += kv.second;       // sweep to get current coverage
            int already = 0;
            auto it = countByValue.find(v);
            if (it != countByValue.end()) already = it->second;
            // We can convert at most numOperations elements; others must already be v
            ans = max(ans, min<int>( (int)cover, already + numOperations ));
        }
        return ans;
    }
};
