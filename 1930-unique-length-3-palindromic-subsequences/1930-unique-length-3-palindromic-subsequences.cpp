class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char, int> mp;
        int ans = 0;
        vector<int> visited(26, 0);
        int left = 0;
        int right = s.size() - 1;
        int n = s.size();
        while (left < n) {
            int x = s[left] - 'a';
            if (visited[x] == 1) {
                left++;
                continue;
            }

            int right = n - 1;
            // 오른쪽에서 같은 문자 찾기
            while (right > left && s[right] != s[left]) {
                right--;
            }


            if (right == left) {
                // 같은 문자를 못 찾음
                left++;
                continue;
            }
            vector<int> seen(26, 0);
            for (int i = left + 1; i < right; i++) {
                seen[s[i] - 'a'] = 1;
            }

            int cnt = 0;
            for (int i = 0; i < 26; i++) cnt += seen[i];

            ans += cnt;

            visited[x] = 1;
            left++;
        }
        return ans;
    }
};