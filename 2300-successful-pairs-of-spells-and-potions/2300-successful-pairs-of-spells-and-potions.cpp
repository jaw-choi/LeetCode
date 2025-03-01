class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        int size_ = 0;
        for(int i=0;i<spells.size();i++)
        {
            size_ = potions.size();
            double border = success / (double)spells[i];
            for(int j=0;j<potions.size();j++)
            {
                if((double)potions[j] < border)
                    size_--;
                else
                    break;
            }
            ans.push_back(size_);
        }
        return ans;
    }
};