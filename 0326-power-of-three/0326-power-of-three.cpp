class Solution {
public:
    bool isPowerOfThree(int n) {
        set<int> s;
        long long num = 1;
        while(num<INT_MAX)
        {
            s.insert(num);
            num*=3;
        }
        return s.find(n)!=s.end();
    }
};