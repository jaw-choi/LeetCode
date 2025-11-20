struct DSU
{
    vector<int> parent;
    vector<int> rank;
    DSU(int n)
    {
        parent.assign(n,{});
        rank.assign(n,0);
        for(int i=0;i<n;i++)
            parent[i] = i;
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);

        if(a==b) return;

        if(rank[a] < rank[b]){
            parent[a] = b;
        }
        else if(rank[b] < rank[a]){
            parent[b] = a;
        }
        else{
            parent[b] = a;
            rank[a]++;
        }
    }

};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isConnected[i][j]==1){
                    dsu.unite(i,j);
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(dsu.parent[i] == i)
                cnt++;
        }
        return cnt;
    }
};