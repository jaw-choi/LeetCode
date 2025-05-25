class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        int cnt = 0;
        unordered_map<string, int> diff, same;
        for (const auto& word : words) {
            if (word[0] == word[1])
                same[word]++;
            else
                diff[word]++;
        }

        for (const auto& [word, count] : diff) {
            string rev = {word[1], word[0]};
            if (diff.count(rev)) {
                int pairCount = min(count, diff[rev]);
                ans += pairCount * 4;
                diff[rev] = 0; // 중복 처리 방지
            }
        }

        int centerUsed = 0, centerMax = 0;
        for (const auto& [word, count] : same) {
            ans += (count / 2) * 4;
            if (count % 2 == 1)
                centerMax = 2; // 중앙에 배치할 수 있는 팰린드롬 1개
        }

        return ans + centerMax;
    }
};
