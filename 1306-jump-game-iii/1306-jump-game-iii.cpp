class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        int idx = start;
        int n = arr.size();
        vector<int> visited(n,0);
        q.push(idx);
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            if(curr < 0 || curr >=n || visited[curr]==1) 
                continue;
            if(arr[curr]==0) 
                return true;
            visited[curr]=1;

            q.push(curr-arr[curr]);
            q.push(curr+arr[curr]);
        }
        return false;
    }
};