bool cmp1(const vector<int>& a, const vector<int>& b) 
{
     return a[1] > b[1];
}

bool cmp2(const vector<int>& a, const vector<int>& b) 
{
     return abs(a[1] - a[0]) > abs(b[1] - b[0]); 
}


class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int ans = 0;
        sort(tasks.begin(), tasks.end(), cmp1);
        ans = tasks[0][1];
        sort(tasks.begin(), tasks.end(), cmp2);
        int cnt1 = -1;
        int tmp = ans;
        int cnt = 0;
        for (int i=0;i<tasks.size();i++)
        {
            cout << tasks[i][1] << endl;
            if(ans == tasks[i][1])
                cnt1++;

            if(i==tasks.size()-1)
            {
                cnt += tasks[i][1];
                break;
            }
            cnt += tasks[i][0];
            if(tmp < tasks[i][1])
            {
                ans += abs(tmp-tasks[i][1]);
                tmp = tasks[i][1];
            }
            tmp -= tasks[i][0];
        }

        return max(ans,cnt);
    }
};
// MAX((모든 r값 합 - 시그마(R-L)) , 모든 L값)
// 57-(36),21 = 21
// 6,5,4,3,2,7 = 27
// 10,10,8,2,3 = 
// [10,12],[10,11],[8,9],[2,4],[[1,3]]