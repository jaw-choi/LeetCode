struct DSU{
    vector<int> parent;
    vector<int> rank;
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
            parent[i]=i;
    }
    int find(int x)
    {
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a,int b)
    {
        a = find(a);
        b = find(b);

        if(a == b)
            return;
        
        if(rank[a]<rank[b])
            parent[a] = b;
        else if(rank[a] > rank[b])
            parent[b] = a;
        else
        {
            parent[b] = a;
            rank[a]++;
        }

    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& C) {

        int n = C.size();
        vector<vector<int>> graph(n);
        vector<int> level(n,0);
        for(int i=0;i<C.size();i++)
        {
            for(int j=0;j<C[i].size();j++)
            {
                if(i==j) continue;
                if(C[i][j]==1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        DSU dsu(n);

        for(int i=0;i<C.size();i++)
        {
            for(int j=i+1;j<C[i].size();j++)
            {
                if(C[i][j]==1)
                    dsu.unite(i,j);
                
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(dsu.find(i)==i)
                cnt++;
        }
        return cnt;
    }
};