class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        int ans = 1e9;
        int idx = 0;
        int cnt = 0;
        int lastTime = 0;
        unordered_map<int,int> mp;
        for(auto p : passengers)
            mp[p]++;
        sort(passengers.begin(),passengers.end());
        sort(buses.begin(),buses.end());
        
        for(int i=0;i<buses.size();i++)
        {
            int busTime = buses[i];
            cnt = 0;
            while(idx<passengers.size() && cnt<capacity && passengers[idx]<=busTime)
            {
                lastTime = passengers[idx];
                cnt++;
                idx++;
            }

        }
        //cout << cnt << idx;
        int lastBus = buses[buses.size()-1];
        if(cnt<capacity && lastTime < lastBus)
            return lastBus;

        while(mp.find(lastTime)!=mp.end())
            lastTime--;
        return lastTime;
    }
};
//4,11,13,19,21,25,26