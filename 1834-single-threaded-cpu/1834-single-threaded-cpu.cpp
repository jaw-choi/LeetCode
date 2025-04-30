class Solution {
public:
struct cmp{
    bool operator()(vector<int>& a,vector<int>& b)
    {
        if(a[1]==b[1])
            return a[2]>b[2];
        return a[1]>b[1];
    }
};
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        long long curr = 0;
        vector<int> ans;
        for(int i=0;i<tasks.size();i++)
            tasks[i].push_back(i);
        sort(tasks.begin(),tasks.end());
        priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
        pq.push(tasks[0]);
        curr=tasks[0][0];
        for(auto t : tasks)
            cout <<t[2];
            cout <<endl;
        for(int i=1;i<tasks.size();)
        {
            while(i<tasks.size() && tasks[i][0]<=curr){
                pq.push(tasks[i]);
                i++;
            }
            if(pq.empty()){
                //i++;
                curr=tasks[i][0];
                continue;
            }
            ans.push_back(pq.top()[2]);
            curr+=pq.top()[1];
            pq.pop();
            //something - one
        }
        queue<vector<int>> tmp;
        while(!pq.empty())
        {
            cout << curr <<": ";
            if(pq.top()[0]<=curr){
                    cout <<pq.top()[0]<<","<<pq.top()[1]<<","<<pq.top()[2];

                ans.push_back(pq.top()[2]);
                curr+=pq.top()[1];
                pq.pop();
            }
            else{
                while(pq.top()[0]>curr){
                    tmp.push(pq.top());
                    pq.pop();
                }
                if(pq.top()[0]<=curr){
                    cout <<pq.top()[0]<<","<<pq.top()[1]<<","<<pq.top()[2];
                    ans.push_back(pq.top()[2]);
                    curr+=pq.top()[1];
                    pq.pop();
                }
                while(!tmp.empty()){
                    pq.push(tmp.front());
                    tmp.pop();
                }
            }
            cout <<endl;
        }
        //
        return ans;
    }
};