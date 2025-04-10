class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        long long answer = 0;
        long long num = 0;
        for(int i=0;i<=limit;i++)
        {
            string tmp = to_string(i) + s;
            num = stoi(tmp);
            if(num>=start && num<=finish)
                answer++;
        }
        return answer;
    }
};