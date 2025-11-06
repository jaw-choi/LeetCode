#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> compId;
vector<bool> offline;
vector<priority_queue<int, vector<int>, greater<int>>> comps;

void dfs(int u, int id) {
    compId[u] = id;
    comps[id].push(u);
    for (int v : graph[u]) {
        if (compId[v] == -1)
            dfs(v, id);
    }
}

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        graph.assign(c + 1, {});
        compId.assign(c + 1, -1);
        offline.assign(c + 1, false);

        for (auto& e : connections) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int id = 0;
        comps.clear();
        comps.reserve(c);

        for (int i = 1; i <= c; i++) {
            if (compId[i] == -1) {
                comps.push_back(priority_queue<int, vector<int>, greater<int>>());
                dfs(i, id++);
            }
        }

        vector<int> ans;

        for (auto& q : queries) {
            int op = q[0], x = q[1];

            if (op == 2) {  // offline
                offline[x] = true;
                continue;
            }

            if (!offline[x]) {  // online
                ans.push_back(x);
                continue;
            }

            int cid = compId[x];
            auto& pq = comps[cid];

            while (!pq.empty() && offline[pq.top()])
                pq.pop();

            if (pq.empty())
                ans.push_back(-1);
            else
                ans.push_back(pq.top());
        }

        return ans;
    }
};
