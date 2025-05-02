class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string result = dominoes;
        int i = 0, j = 0;

        while (i < n) {
            // 다음 도미노 위치 찾기
            while (j < n && result[j] == '.') j++;

            char left = (i == 0) ? 'L' : result[i - 1];
            char right = (j == n) ? 'R' : result[j];

            if (left == right) {
                for (int k = i; k < j; ++k)
                    result[k] = right;
            } else if (left == 'R' && right == 'L') {
                int l = i, r = j - 1;
                while (l < r) {
                    result[l++] = 'R';
                    result[r--] = 'L';
                }
                // 가운데가 홀수면 자동으로 '.' 유지됨
            }
            // else: 'L'...'R' 은 아무것도 안 바꿈

            i = j + 1;
            j = i;
        }

        return result;
    }
};
