class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        stack<int> st;
        for(auto& n : nums)
        {
            st.push(n);
            while(st.size()>=2)
            {
                int num = st.top();
                st.pop();
                int cmp = st.top();
                st.pop();
                if(gcd(num,cmp)>1)
                {
                    st.push(lcm(num,cmp));
                }
                else{
                    st.push(cmp);
                    st.push(num);
                    break;
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};