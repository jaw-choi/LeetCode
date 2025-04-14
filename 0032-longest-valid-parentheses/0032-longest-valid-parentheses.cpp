class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<int> v(s.size(),0);
        //st.push(0);
        for(int i=0;i<s.size();i++)
        {
            if(st.empty()){
                st.push(i);
                continue;
            }
            if(s[st.top()]=='(' && s[i]==')'){
                v[st.top()]=1;
                v[i]=1;
                st.pop();
            }
            else
                st.push(i);
        }
        int tmp = 0;
        int ans = 0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==1)
                tmp++;
            else
                tmp = 0;
            ans = max(ans,tmp);
        }

        return ans;
    }
};