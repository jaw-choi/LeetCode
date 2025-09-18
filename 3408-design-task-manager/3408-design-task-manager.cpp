struct Compare {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.first == b.first)
            return a.second > b.second;  // second 내림차순
        return a.first > b.first;        // first 내림차순
    }
};
class TaskManager {
public:
    void print(map<int,int>& TaskIdPriority,map<pair<int,int>,int,Compare>& PriorityTaskIdUserId)
    {
        cout << "TaskIdPriority " <<endl;
        for(auto& n: TaskIdPriority)
        {
            cout << n.first << "," << n.second<<endl;
        }
        cout << "PriorityTaskIdUserId " <<endl;
        for(auto& n: PriorityTaskIdUserId)
        {
            cout << n.first.first<<","<<n.first.second << ":" << n.second<<endl;
        }
    }
    TaskManager(vector<vector<int>>& tasks) {
        //mtask = tasks;
        for(auto& t : tasks)
        {
            int userId = t[0];
            int taskId = t[1];
            int priority = t[2];
            TaskIdPriority[taskId] = priority;
            PriorityTaskIdUserId[{priority,taskId}]=userId;
        }
        //print(TaskIdPriority,PriorityTaskIdUserId);
    }
    
    void add(int userId, int taskId, int priority) {
        //mtask.push_back({userId,taskId,priority});
        TaskIdPriority[taskId] = priority;
        PriorityTaskIdUserId[{priority,taskId}]=userId;
        //print(TaskIdPriority,PriorityTaskIdUserId);
    }
    
    void edit(int taskId, int newPriority) {
        int priority = TaskIdPriority[taskId];
        int userId = PriorityTaskIdUserId[{priority,taskId}];
        PriorityTaskIdUserId.erase({priority,taskId});
        TaskIdPriority[taskId] = newPriority;
        PriorityTaskIdUserId[{newPriority,taskId}]=userId;
        //print(TaskIdPriority,PriorityTaskIdUserId);
    }
    
    void rmv(int taskId) {
        PriorityTaskIdUserId.erase({TaskIdPriority[taskId],taskId});
        TaskIdPriority.erase(taskId);

    }
    
    int execTop() {
        if(PriorityTaskIdUserId.empty())
            return -1;
        auto it = PriorityTaskIdUserId.begin();
        int userId = it->second;
        TaskIdPriority.erase(it->first.second);
        PriorityTaskIdUserId.erase(it);
        return userId;
    }
private:
    //vector<vector<int>> mtask;
    map<int,int> TaskIdPriority;
    map<pair<int,int>,int,Compare> PriorityTaskIdUserId;
    //set<pair<int,int>> priorityTaskId;
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */