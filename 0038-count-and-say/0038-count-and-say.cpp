class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";

        string prev = countAndSay(n - 1);
        string curr;
        
        for (int j = 0, start = 0; j <= prev.size(); ++j) {
            if (j == prev.size() || prev[j] != prev[start]) {
                int cnt = j - start;
                curr += to_string(cnt) + prev[start];
                start = j;
            }
        }

        return curr;
    }
};