class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int p = 0;
        int t = 0;
        int cnt = 0;
        while(p<players.size() && t<trainers.size())
        {
            if(players[p] <= trainers[t]){
                cnt++;
                p++;
                t++;
            }
            else{
                t++;
            }
        }
        return cnt;
        //4,7,9
        //2,5,8,8
    }
};