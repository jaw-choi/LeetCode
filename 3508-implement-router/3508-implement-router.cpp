#include <bits/stdc++.h>
using namespace std;

class Router {
public:
    Router(int memoryLimit) : lmt(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        vector<int> packet = {source, destination, timestamp};
        if (s.find(packet) != s.end()) return false;

        if (q.size() == lmt) {
            auto old = q.front(); q.pop();
            s.erase(old);

            auto& vec = mp[old[1]];
            auto it = lower_bound(vec.begin(), vec.end(), old[2]);
            if (it != vec.end() && *it == old[2]) vec.erase(it);
        }

        s.insert(packet);
        q.push(packet);

        auto& vec = mp[destination];
        auto it = lower_bound(vec.begin(), vec.end(), timestamp);
        vec.insert(it, timestamp); // 항상 정렬 유지
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto packet = q.front(); q.pop();
        s.erase(packet);

        auto& vec = mp[packet[1]];
        auto it = lower_bound(vec.begin(), vec.end(), packet[2]);
        if (it != vec.end() && *it == packet[2]) vec.erase(it);

        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        if (mp.find(destination) == mp.end()) return 0;
        auto& vec = mp[destination];
        auto it1 = lower_bound(vec.begin(), vec.end(), startTime);
        auto it2 = upper_bound(vec.begin(), vec.end(), endTime);
        return (int)(it2 - it1); // O(log n)
    }

private:
    int lmt;
    set<vector<int>> s;
    queue<vector<int>> q;
    map<int, vector<int>> mp; // 목적지별 정렬된 timestamp 저장
};


