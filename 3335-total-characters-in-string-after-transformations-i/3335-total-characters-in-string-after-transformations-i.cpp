class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        constexpr int mod = 1e9 + 7;
        int ans = 0;
        int cnt[26];
        //vector<int> cnt(26);
        for(auto ch : s)
            cnt[ch-'a']++;

        for(int i=0;i<t;i++)
        {
            int nxt[26]={};
            nxt[0] = cnt[25];
            nxt[1] = (cnt[25]+cnt[0])%mod;
            for(int j=2;j<26;j++)
            {
                nxt[j] = cnt[j-1];
            }
            // cnt = move(nxt);
            copy(nxt, nxt + 26, cnt);
        }
        for(auto c : cnt)
            ans = (ans+c)%mod;

        return ans;
    }
};
struct FastIO {
    FastIO() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fastio;