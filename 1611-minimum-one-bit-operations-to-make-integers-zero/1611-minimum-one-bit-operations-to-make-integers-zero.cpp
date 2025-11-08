#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // O(log n) solution using XOR pattern
    int minimumOneBitOperations(int n) {
        int ans = 0;
        while (n > 0) {
            ans ^= n;
            n >>= 1;
        }
        return ans;
    }
};
