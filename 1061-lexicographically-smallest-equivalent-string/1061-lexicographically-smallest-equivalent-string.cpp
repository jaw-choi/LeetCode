class Solution {
public:
    char dfs(unordered_map<char,vector<char>>& mp, char ch, vector<int>& visited)
    {
        visited[ch - 'a'] = 1;
        char minChar = ch;
        for(auto n : mp[ch])
        {
            if(visited[n - 'a']==0){
                minChar = min(minChar,dfs(mp,n,visited));
            }
        }
        return minChar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        unordered_map<char,vector<char>> mp;

        for(int i=0;i<n;i++)
        {
            mp[s1[i]].push_back(s2[i]);
            mp[s2[i]].push_back(s1[i]);
        }

        string ans = "";
        for(auto ch : baseStr)
        {
            vector<int> visited(26,0);
            char minChar = dfs(mp,ch,visited);
            ans += minChar;
        }
        return ans;
    }
};