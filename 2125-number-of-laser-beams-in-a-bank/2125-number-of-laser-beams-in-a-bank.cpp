class Solution {
public:
    int CountLaser(string& str)
    {
        int cnt=0;
        for(auto& s : str)
        {
            if(s=='1')
                cnt++;
        }
        return cnt;
    }
    int numberOfBeams(vector<string>& bank) {
        int answer = 0;
        int laser = 0;
        int cnt = 0;
        for(int i=0;i<bank.size();i++)
        {
            cnt = CountLaser(bank[i]);
            if(cnt!=0)
            {
                answer += (cnt * laser);
                laser = cnt;
            }
        }
        return answer;
    }
};