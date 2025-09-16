class Solution {
public:
    bool isNCP(int a, int b) { return getGCM(a, b) > 1; }
    int getGCM(int a, int b) {
        if (b == 0)
            return a;
        return getGCM(b, a % b);
    }
    int getLCM(int a, int b) { return ((long long)a * b) / getGCM(a, b); }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> answer;
        stack<int> st;
        int LCM = 0;
        int prev = 0;
        int n = nums.size();
        int idx = 0;
        for(auto& x : nums) {
            st.push(x);

            while(st.size() >= 2) {
                int right = st.top(); st.pop();
                int left = st.top(); st.pop();
                if (isNCP(left,right)) {
                    LCM = getLCM(left,right);
                    st.push(LCM);
                    // cout << LCM << " " << left << " " << right << endl;
                } else {
                    st.push(left);
                    st.push(right);
                    break;
                }
            }

        }
        while(!st.empty()) {
            int num = st.top();
            cout << num << " ";
            st.pop();
            answer.push_back(num);
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};