class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s;
        int ans = 0;
        for(auto& num : arr1)
        {
            while(s.find(num)==s.end())
            {
                s.insert(num);
                num/=10;
                if(num==0) break;
            }
        }

        for(auto& num : arr2)
        {
            while(s.find(num)==s.end())
            {
                num/=10;
                if(num==0) break;
            }
            if(ans < num)
                ans = num;
        }
        cout << ans;
        int cnt = 0;
        while(ans!=0)
        {
            ans /= 10;
            cnt++;
        }
        return cnt;
    }
};