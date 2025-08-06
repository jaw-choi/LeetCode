class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        // sort(fruits.rbegin(),fruits.rend());
        // sort(baskets.rbegin(),baskets.rend());
        // int ans = 0;
        // for(int i=0;i<fruits.size();i++)
        // {
            
        // }
        int ans = 0;
        set<int> visited;
        for(int i=0;i<fruits.size();i++)
        {
            for(int j=0;j<baskets.size();j++)
            {
                if(visited.find(j)==visited.end()){
                    if(fruits[i] <= baskets[j]){
                        visited.insert(j);
                        break;
                    }
                }
                if(j==baskets.size()-1)
                    ans++;
            }
        }
        return ans;
    }
};